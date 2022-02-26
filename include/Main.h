#pragma once
#include "NierHook.hpp"
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/wx.h>

class Main : public wxFrame, public wxThreadHelper
{
  public:
    Main();
    ~Main();

  public:
    NieRHook* hook = nullptr;

    // UI Thread Timer
    wxTimer* m_Timer = nullptr;

    // HOOK STATUS
    wxStaticText* m_hooked = nullptr;
    wxStaticText* m_status = nullptr;
    wxStaticText* m_version = nullptr;
    wxStaticText* m_gameVer = nullptr;

    // Tabs
    wxNotebook* notebook = nullptr;
    wxPanel* Player = nullptr;
    wxPanel* Inventory = nullptr;
    wxPanel* Weapons = nullptr;
    wxPanel* Settings = nullptr;

  protected:
    void updateComponents(void);
    void startTimer(void);
    void stopTimer(void);
    void OnTimer(wxTimerEvent&);
    virtual wxThread::ExitCode Entry();
    void OnThreadUpdate(wxThreadEvent& evt);
    void OnClose(wxCloseEvent& evt);
    void StartHook(void);
    wxDECLARE_EVENT_TABLE();
};
