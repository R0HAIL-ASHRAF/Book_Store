#pragma once

#include <wx/wx.h>
#include <wx/statbmp.h>
#include <wx/sizer.h>
#include <wx/image.h>
#include <wx/statline.h>
#include"Stationary.h"
#include"IDs.h"

class StationaryDisplayPanel :public wxPanel
{
public:
	StationaryDisplayPanel(wxWindow* parent);
	void SetStationaryInfo(const Stationary& stationary);
private:
    wxStaticText* m_productIdText;
    wxStaticText* m_productNameText;
    wxStaticText* m_stationaryTypeText;
    wxStaticText* m_stationaryBrandText;
    wxStaticText* m_stationaryColorText;
    wxStaticText* m_priceText;
    wxStaticText* m_descriptionText;
    wxStaticText* m_noCoverText;
    wxStaticBitmap* m_imagePreview;

    void CreateControls();
};

