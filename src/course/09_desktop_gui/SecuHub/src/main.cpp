#include <wx/wx.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/font.h>
#include <wx/panel.h>
#include <wx/event.h>
#include <unordered_map>

// Custom clickable panel
class ClickableWidget : public wxPanel {
public:
    ClickableWidget(wxWindow* parent, const wxString& iconPath, const wxString& text, std::function<void()> callback)
        : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(120, 120)), m_callback(callback)
    {
        SetBackgroundColour(*wxWHITE);
        SetCursor(wxCursor(wxCURSOR_HAND));

        auto* box = new wxBoxSizer(wxVERTICAL);

        // Icon
        wxBitmap bitmap(iconPath, wxBITMAP_TYPE_PNG);
        auto* icon = new wxStaticBitmap(this, wxID_ANY, bitmap);
        box->Add(icon, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

        // Text
        auto* label = new wxStaticText(this, wxID_ANY, text);
        label->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
        box->Add(label, 0, wxALIGN_CENTER | wxBOTTOM, 5);

        SetSizer(box);
        Bind(wxEVT_ENTER_WINDOW, &ClickableWidget::OnHover, this);
        Bind(wxEVT_LEAVE_WINDOW, &ClickableWidget::OnLeave, this);
        Bind(wxEVT_LEFT_DOWN, &ClickableWidget::OnClick, this);
    }

private:
    std::function<void()> m_callback;

    void OnHover(wxMouseEvent&) {
        SetBackgroundColour(wxColour(224, 224, 224)); // light grey
        Refresh();
    }

    void OnLeave(wxMouseEvent&) {
        SetBackgroundColour(*wxWHITE);
        Refresh();
    }

    void OnClick(wxMouseEvent&) {
        SetBackgroundColour(wxColour(179, 229, 252)); // light blue
        Refresh();
        if (m_callback) m_callback();
    }
};

// Main application frame
class SecureHubFrame : public wxFrame {
public:
    SecureHubFrame() : wxFrame(nullptr, wxID_ANY, "CASD Secure Hub", wxDefaultPosition, wxSize(800, 600)) {
        SetIcon(wxIcon("./assets/bouclier.png", wxBITMAP_TYPE_PNG));

        auto* panel = new wxPanel(this);
        auto* vbox = new wxBoxSizer(wxVERTICAL);

        // Logo
        wxBitmap logo("./assets/casd.png", wxBITMAP_TYPE_PNG);
        auto* logoCtrl = new wxStaticBitmap(panel, wxID_ANY, logo);
        vbox->Add(logoCtrl, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 20);

        // Welcome Text
        auto* welcomeText = new wxStaticText(panel, wxID_ANY, "Welcome to the CASD Secure HUB");
        welcomeText->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
        welcomeText->SetForegroundColour(wxColour(128, 128, 128)); // grey
        vbox->Add(welcomeText, 0, wxALIGN_CENTER | wxBOTTOM, 20);

        // Grid of clickable icons
        wxGridSizer* grid = new wxGridSizer(4, 10, 10); // 4 columns

        for (int i = 1; i <= 4; ++i) {
            wxString label = wxString::Format("Server %d", i);
            auto* icon = new ClickableWidget(panel, "./assets/server.png", label, [=]() {
                outputLabel->SetLabel("Connect to server: " + label);
            });
            grid->Add(icon, 0, wxALIGN_CENTER);
        }

        vbox->Add(grid, 0, wxALIGN_CENTER | wxBOTTOM, 20);

        // Output Label
        outputLabel = new wxStaticText(panel, wxID_ANY, "Select the server you want to connect to");
        outputLabel->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
        vbox->Add(outputLabel, 0, wxALIGN_CENTER | wxTOP, 20);

        panel->SetSizer(vbox);
        Centre();
    }

private:
    wxStaticText* outputLabel;
};

// wxWidgets entry point
class SecureHubApp : public wxApp {
public:
    bool OnInit() override {
        SecureHubFrame* frame = new SecureHubFrame();
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(SecureHubApp);
