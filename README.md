# Computer Graphics

Applications made with GLUT library.

## Projects

The following projects have been made with GLUT and compiled with `GCC`

### Color and Gradient

Draws a 4-color gradient square

![image](https://user-images.githubusercontent.com/12193814/87869521-cfed9800-c976-11ea-8373-ed5a65df4385.png)

### Geometric Figures

Draws a letter made with many polygons and geometric shapes

![image](https://user-images.githubusercontent.com/12193814/87869559-21962280-c977-11ea-8759-333f51dc912b.png)

### Keyboard and Mouse

Allows the user to draw different objects in white canvas and change it's color, using keyboard and mouse

![image](https://user-images.githubusercontent.com/12193814/87869686-02e45b80-c978-11ea-993a-d68d5d955583.png)

### Keyboard and Math Functions

Allows the user to draw and erase mathematical functions into a cartesian coordinate system, using the keyboard

![image](https://user-images.githubusercontent.com/12193814/87869715-30c9a000-c978-11ea-803a-762a8e773057.png)

### Paint Prototype

This Paint graphic editor imitation, allows user to draw shapes with vertices and change its color, using keyboard and mouse

![image](https://user-images.githubusercontent.com/12193814/87869814-16dc8d00-c979-11ea-86ce-80ad899054ee.png)

## Running the Project

To get started, fork the repository and then run the instructions below:

- Install GLUT library opening your Linux terminal and typing:

      sudo apt update && sudo apt-get install freeglut3-dev -y

- Follow one of the two options presented:

### 1) With Visual Studio Code:

1. Install [Visual Studio Code](https://code.visualstudio.com/Download) (text editor)
2. Install the [plugin](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) for C/C++
3. Open the text editor and import the project folder with menu `File > Open Folder`
4. Select the C/C++ file you want to compile
5. Press `Ctrl + Shift + B` or menu `Terminal > Run Build Task` to compile it
6. Go to the text editor's terminal and open the file typing: `./my-file-name`

**Obs:** Change `"command"` line from `tasks.json` file to:

- `"command":"gcc"` to compile C files
- `"command":"g++"` to compile C++ files

### 2) With another text editor or IDE

1. Open the project folder in your favorite text editor or IDE (Integrated Development Environment)
2. Select the C/C++ file you want to compile
3. Open your text editor/IDE terminal and compile the file typing `gcc file-name.c -o file-name -lm -lGL -lGLU -lglut` or use your IDE compiling option
4. Go to the text editor's terminal and open the file typing: `./my-file-name`

### BONUS: How to create a build makefile with VS Code:

1. Open the text editor
2. Press `Ctrl + Shift + P`
3. Write and select `Tasks: Configure Default Build Task`
4. Select `C/C++: gcc build active file`
5. The task file is created inside the folder called `.vscode`
