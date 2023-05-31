using Effekseer.GUI;

namespace Effekseer.GUI.Dialog
{
	class HelloWorld : IRemovableControl
	{
		string _id = "###HelloWorld";
		string _title = "Hello World";
		string _content = "HELLO WORLD!";

		bool _isFirstUpdate = true;

		bool _opened = true;

		public bool ShouldBeRemoved { get; private set; } = false;

		public void Show()
		{
			Manager.AddControl(this);
		}

		public void Update()
		{
			if (_isFirstUpdate)
			{
				Manager.NativeManager.OpenPopup(_id);
				Manager.NativeManager.SetNextWindowSize(600 * Manager.DpiScale, 400 * Manager.DpiScale, Effekseer.swig.Cond.Appearing);
				_isFirstUpdate = false;
			}

			if (Manager.NativeManager.BeginPopupModal(_title + _id, ref _opened, Effekseer.swig.WindowFlags.None))
			{
				const float iconSize = 64;

				Manager.NativeManager.ImageData(Images.GetIcon("AppIcon"), iconSize, iconSize);

				Manager.NativeManager.SameLine();

				Manager.NativeManager.SetCursorPosY(Manager.NativeManager.GetCursorPosY() + iconSize / 2 - Manager.NativeManager.GetTextLineHeight() / 2);
				Manager.NativeManager.Text(_content);

				Manager.NativeManager.Separator();

				Manager.NativeManager.Separator();

				Manager.NativeManager.SetCursorPosX(Manager.NativeManager.GetContentRegionAvail().X / 2 - 100 / 2);

				if (Manager.NativeManager.Button("OK", 100))
				{
					ShouldBeRemoved = true;
				}

				Manager.NativeManager.EndPopup();
			}
			else
			{
				ShouldBeRemoved = true;
			}
		}
	}
}
