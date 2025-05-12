// This application creates a window with a label that says "Hello, World!" and a button labeled "Click Me"
// When you click the button, the label changes to "Button Clicked!"

#include <wx/wx.h>
// use the wxWidgets header file that contains declarations for wxWidgets classes and functions
// wxWidgets is a C++ library for creating graphical user interfaces (GUIs).
#include <wx/mstream.h>
#include "casd_png.h"

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

wxBitmap MyFrame::LoadEmbeddedImage()
{
    wxMemoryInputStream stream(casd_png, casd_png_len);
    wxImage image(stream, wxBITMAP_TYPE_PNG);
    return wxBitmap(image);
}