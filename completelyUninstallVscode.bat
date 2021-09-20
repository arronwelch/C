    explorer.exe %appdata%
    del Code

    explorer.exe %UserProfile%\.vscode
    del .vscode

    start "%LocalAppData%\Programs\Microsoft VS Code" unins000.exe