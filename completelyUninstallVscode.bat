
    start "%LocalAppData%\Programs\Microsoft VS Code" unins000.exe

    explorer.exe %appdata%
    del Code

    explorer.exe %UserProfile%\.vscode
    del .vscode