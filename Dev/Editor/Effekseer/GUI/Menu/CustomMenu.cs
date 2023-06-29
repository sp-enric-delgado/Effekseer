using Effekseer.SDK;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;

namespace Effekseer.GUI.Menu
{
	internal class CustomMenu
	{
		private static readonly List<CustomPlugin> pluginArray = new List<CustomPlugin>();

		public Menu SetUpCustomMenu()
		{
			// Create Menú Section
			var menu = new Menu(new MultiLanguageString("Custom"));

			// Read through all plugins and add it to the plugins array
			//pluginArray.AddRange(ReadPlugins());

			foreach (var setting in pluginArray)
			{
				setting.AddTo(menu);

				if (setting.IconName == "ProceduralModel_Name")
				{
					menu.Controls.Add(new MenuSeparator());
				}
			}

			menu.Controls.Add(new MenuSeparator());

			// Create Add Custom Script Option
			{
				var item = new MenuItem();
				item.Label = new MultiLanguageString("Add Custom Script...");
				item.Clicked += AddCustomScript;
				menu.Controls.Add(item);
			}

			return menu;
		}

		static public void AddCustomScript()
		{
			var filter = MultiLanguageTextProvider.GetText("ProjectFilterNew");
			var result = swig.FileDialog.OpenDialog(filter, Directory.GetCurrentDirectory());

			if (!string.IsNullOrEmpty(result))
			{
				Commands.Open(result);
			}
		}

		static List<CustomPlugin> ReadPlugins()
		{
			List<CustomPlugin> plugins = new List<CustomPlugin>();
			var extensionsDirectory = AppDomain.CurrentDomain.BaseDirectory + "/extensions";
			var files = Directory.GetFiles(extensionsDirectory);

			foreach (var file in files)
			{
				var assembly = Assembly.LoadFile(Path.Combine(Directory.GetCurrentDirectory(), file));
				var pluginTypes = assembly.GetTypes().Where(t => typeof(IPlugin).IsAssignableFrom(t) && !t.IsInterface).ToArray();

				foreach (var pluginType in pluginTypes)
				{
					var plugin = Activator.CreateInstance(pluginType) as CustomPlugin;
					plugins.Add(plugin);
				}
			}

			return plugins;
		}

		private sealed class CustomPlugin : IPlugin
		{
			private readonly Type _type;

			public string PluginName { get; }

			public string IconName { get; }

			public CustomPlugin(string title, Type type, string iconName)
			{
				PluginName = title;
				_type = type;
				IconName = iconName;
			}

			public void AddTo(Menu menu)
			{
				var item = new MenuItem();
				item.Label = new MultiLanguageString(PluginName);
				item.Icon = IconName;
				item.Clicked += () => Manager.SelectOrShowWindow(_type, new swig.Vec2(300, 300), true);
				item.OnUpdate = () =>
				{
					var dock = Manager.GetWindow(_type);
					item.Checked = dock != null;
				};

				menu.Controls.Add(item);
			}
		}
	}
}