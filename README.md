# Programming

- it is a workspace while I am preparing for interviews
- this workspace contains pre-written tasks for **debugging**, **running** c++ files,and **cleaning** output files files quickly from vscode

#### before using this workspace
- if you want to use this workspace you have to follow steps:
	- change c++ compiler in `.vscode/tasks.json`, I used gcc compiler on mac and set path according to that, you can set path to c++ compiler according to your system.

#### for windows users
- Windows user in to use cmd as a default terminal to run files throught `vscode tasks`
- you can add below line in `.vsode/settings.jso`n to make CMD as default terminal
``` json
"terminal.integrated.defaultProfile.windows": "Command Prompt"
```
- you still need to use git bash for cleaning output files in workspace

#### how to run a particular file
- open the c++ file you want to run **(file must be open)** in order run that file
- press `command/control + shift + P` type `run build task` press enter to run the task.

#### clean workspace
- if you can run bash files from your system run `bash clean.sh` to remove unwanted build files and directories.

### Search with Tags
 you can use `grep -E '#two-pointer|#array|#medium' -rl src` to get the list particular kind of questions

Thank you 😄