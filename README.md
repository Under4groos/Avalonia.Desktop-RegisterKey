# Avalonia.Desktop-RegisterKey ( Using Windows 11)
Дерма карета 

# Build
```
1. dll_lib.cpp compile to WinShellLib.dll
2. Copy WinShellLib.dll from application (.exe)

```





```cs
public class HotKeyBind
{
    public bool Status = false;
    public HotKeyBind(WinFormKeys winFormKeys, Action<bool> StatusCode)
    {
        new Thread(() =>
        {
            int code = 0;
            // (int)this.GetHwndSource()
            WinApi._RegisterHotKeyBind(0, 1, winFormKeys).Where(() =>
            {
                Console.WriteLine($"Register key: {winFormKeys.ToString()}");

            });
            while (true)
            {
                code = WinApi._GetMessage();
                Status = !Status;
                Console.WriteLine($"Key Status: {Status.ToString()}");

                StatusCode(Status);
            }
        }).Start();

    }
}
```

# MainWindow 
```cs
public partial class MainWindow : Window
{
    private HotKeyBind hotKeyBind;
    public MainWindow()
    {
        InitializeComponent(); 
    }
    protected override void OnLoaded(RoutedEventArgs e)
    {
        hotKeyBind = new HotKeyBind(WinFormKeys.Z, (bool status) =>
        {
            Debug.WriteLine($"Hwnd: {this.GetHwndSource()}");
        });
        base.OnLoaded(e);
    }
}
```

