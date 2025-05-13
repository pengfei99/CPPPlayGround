# Develop desktop gui

In this section, we will learn how to build desktop gui with C++.

We will test two framework:
- QT
- wxWidgets


## 1. Available frameworks

### 1.1. Qt

**Pros:**
- Extremely feature-rich (GUI, networking, multimedia, threading, etc.).
- Cross-platform: Windows, Linux, macOS, Android, iOS.
- Excellent IDE (Qt Creator).
- Modern UI with Qt Quick/QML for declarative GUIs.
- Actively maintained with large community and documentation.

**Cons:**

- Licensing: LGPL 3 (for open source) or paid commercial license.
- Can feel heavy for small/simple apps.

**Best for**: `Professional, modern applications with complex UIs and cross-platform needs.`

### 1.2 wxWidgets

**Pros:**

- Native look and feel (uses platform's native widgets).
- Fully open-source under a liberal license (wxWindows License).
- Lightweight and low dependency footprint.

Cons:

- API feels outdated compared to Qt.
- Weaker community/tools support.
- Less modern styling/customization.

**Best for**: `Lightweight native apps with minimal dependencies and free licensing.`


## 2. Develop a simple app with wxWidgets

### 2.1 Prepare a env dev

You need to have a environment of developement for C++.

```shell
g++ --version
cmake --version
mingw32-make --version
```

### 2.2 Project Structure

```shell
MyWxApp/
├── CMakeLists.txt
├── app.rc
├── app.manifest
├── resource.h
├── assets/bouclier.ico
└── src/main.cpp

```

Below is an example of `main.cpp`

```cpp
// This application creates a window with a label that says "Hello, World!" and a button labeled "Click Me"
// When you click the button, the label changes to "Button Clicked!"

#include <wx/wx.h>
// use the wxWidgets header file that contains declarations for wxWidgets classes and functions
// wxWidgets is a C++ library for creating graphical user interfaces (GUIs).
#include <wx/mstream.h>


// Main application class definition that initializes the program
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

// Main window class that contains the GUI elements
class MyFrame : public wxFrame
{
    // The constructor takes a title as parameter and sets up the window
public:
    MyFrame(const wxString &title);

    // This method is the event handler that's called when the button is clicked
private:
    void OnButtonClick(wxCommandEvent &event);
    wxBitmap LoadEmbeddedImage();

    wxStaticText *label;
    wxButton *button;
};

// wxWidgets macro that sets up the application entry point
wxIMPLEMENT_APP(MyApp);

// Define the OnInit method, which is called when the application MyApp starts
// This method belongs to the MyApp class
bool MyApp::OnInit()
{
    // Create a new instance of MyFrame, which is the main window of the application
    // The title of the window is set to "wxWidgets Simple App"
    MyFrame *frame = new MyFrame("wxWidgets Simple App");
    frame->Show(true);
    return true;
}

// Define the constructor for MyFrame, which sets up the GUI elements
// This constructor belongs to the MyFrame class
MyFrame::MyFrame(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(300, 200))
{

    wxPanel *panel = new wxPanel(this, wxID_ANY);
    // Create a panel to hold the GUI elements
    // Create a static text label with the text "Hello, World!" at position (100, 30) on the panel
    label = new wxStaticText(panel, wxID_ANY, "Hello, World!", wxPoint(100, 30));

    // add an image
    // wxStaticBitmap *img = new wxStaticBitmap(this, wxID_ANY, LoadEmbeddedImage(), wxPoint(50, 50));

    // Create a button with the label "Click Me" at position (100, 70) on the panel
    // The button is created with a unique ID (wxID_ANY) and is associated with the panel
    button = new wxButton(panel, wxID_ANY, "Click Me", wxPoint(100, 70));

    // Bind the button click event to the OnButtonClick method
    // This means that when the button is clicked, the OnButtonClick method will be called
    button->Bind(wxEVT_BUTTON, &MyFrame::OnButtonClick, this);
}

// Define the OnButtonClick method, which is called when the button is clicked
void MyFrame::OnButtonClick(wxCommandEvent &event)
{
    // Change the label text to "Button Clicked!" when the button is clicked
    // This method belongs to the MyFrame class
    label->SetLabel("Button Clicked!");
}

```

> The content of `CMakeLists.txt` is different based on the OS. 
> Below is an example for windows build
>
```cmake
cmake_minimum_required(VERSION 3.14)
project(MyWxApp)

set(CMAKE_CXX_STANDARD 17)
# Set wxWidgets root if needed (for Windows builds)
set(wxWidgets_ROOT_DIR "C:/Users/PLIU/Documents/Tool/CPP_libs/wxWidgets")
set(wxWidgets_LIB_DIR "C:/Users/PLIU/Documents/Tool/CPP_libs/wxWidgets/lib/gcc_lib")

# enable unicode support
set(wxWidgets_USE_UNICODE ON)

# Find static build
set(wxWidgets_USE_STATIC ON)

# Find wxWidgets with desired components
find_package(wxWidgets REQUIRED COMPONENTS net gl media core base)

# Include wxWidgets use file
include(${wxWidgets_USE_FILE})

# Add definitions (optional redundancy)
add_definitions(-DUNICODE -D__UNICODE)

# Define target and link libraries
add_executable(MyWxApp 
    src/main.cpp
    app.rc
    )

target_include_directories(MyWxApp PRIVATE  ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(MyWxApp ${wxWidgets_LIBRARIES})
```

The below file is for removing warning in windows:
- app.rc
- app.manifest
- resource.h

You can find the complete code example in [src/course/09_desktop_gui/MyWxApp/](../src/course/09_desktop_gui/MyWxApp/).


> **I did not be able to add images in to the application.**