# Avalonia.Desktop-RegisterKey
Дерма карета 

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

