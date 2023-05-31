using Effekseer.GUI;

namespace Effekseer.GUI.Dialog
{
	class HelloWorld : IRemovableControl
	{
		string _id = "###HelloWorld";
		string _title = "Hello World";
		string _content = "HELLO WORLD!";

		const float _windowWidth = 200;
		const float _windowHeigth = 200;
		const float _okButtonSize = 100;

		bool _isFirstUpdate = true;

		bool _opened = true;

		public bool ShouldBeRemoved { get; private set; } = false;

		public void Show()
		{
			_title = MultiLanguageTextProvider.GetText("Hello World");
			Manager.AddControl(this);
		}

		public void Update()
		{
			if (_isFirstUpdate)
			{
				Manager.NativeManager.OpenPopup(_id);
				Manager.NativeManager.SetNextWindowSize(_windowWidth * Manager.DpiScale, _windowHeigth * Manager.DpiScale, Effekseer.swig.Cond.Appearing);

				_isFirstUpdate = false;
			}

			if (Manager.NativeManager.BeginPopupModal(_title + _id, ref _opened, Effekseer.swig.WindowFlags.None))
			{
				const float spacing = 32;

				// Add top text spacing
				Manager.NativeManager.SetCursorPosY(Manager.NativeManager.GetCursorPosY() + spacing - Manager.NativeManager.GetTextLineHeight() / 2);


				// Add centering
				Manager.NativeManager.SetCursorPosX(Manager.NativeManager.GetContentRegionAvail().X / 2 - _windowWidth/8);

				// Display message
				Manager.NativeManager.Text(_content);

				// Add bottom spacing
				Manager.NativeManager.SetCursorPosY(Manager.NativeManager.GetCursorPosY() + spacing - Manager.NativeManager.GetTextLineHeight() / 2);


				// Add centering
				Manager.NativeManager.SetCursorPosX(Manager.NativeManager.GetContentRegionAvail().X / 2 - _okButtonSize/2);

				// Display button
				if (Manager.NativeManager.Button("OK", _okButtonSize))
				{
					// Add button functionality
					ShouldBeRemoved = true;
				}

				// End window
				Manager.NativeManager.EndPopup();
			}
			else
			{
				ShouldBeRemoved = true;
			}
		}
	}
}
