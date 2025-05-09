// This application creates a window with a label that says "Hello, World!" and a button labeled "Click Me"
// When you click the button, the label changes to "Button Clicked!"

#include <wx/wx.h>
// use the wxWidgets header file that contains declarations for wxWidgets classes and functions
// wxWidgets is a C++ library for creating graphical user interfaces (GUIs).

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

    wxStaticText *label;
    wxButton *button;
};


// wxWidgets macro that sets up the application entry point
wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame("wxWidgets Simple App");
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(300, 200))
{

    wxPanel *panel = new wxPanel(this, wxID_ANY);

    label = new wxStaticText(panel, wxID_ANY, "Hello, World!", wxPoint(100, 30));
    button = new wxButton(panel, wxID_ANY, "Click Me", wxPoint(100, 70));

    button->Bind(wxEVT_BUTTON, &MyFrame::OnButtonClick, this);
}

void MyFrame::OnButtonClick(wxCommandEvent &event)
{
    label->SetLabel("Button Clicked!");
}