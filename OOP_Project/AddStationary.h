#pragma once

#include"wx/wx.h"
#include <wx/filepicker.h>
#include"IDs.h"
#include <wx/statline.h>
#include"MyString.h"
#include <wx/mstream.h> 
#include"Stationary.h"



class AddStationary :public wxPanel
{
private:
	wxTextCtrl* m_productIdCtrl;
	wxTextCtrl* m_productNameCtrl;
	wxTextCtrl* m_priceCtrl;
	wxTextCtrl* m_descriptionCtrl;
	wxTextCtrl* m_stationaryTypeCtrl;
	wxTextCtrl* m_stationaryBrandCtrl;
	wxTextCtrl* m_stationaryColorCtrl;
	wxFilePickerCtrl* m_imagePicker;
	wxStaticBitmap* m_imagePreview;
	wxImage* m_productImage;
	MyString m_imagePath;

	wxButton* cancelBtn;
	wxButton* clearBtn;
	wxButton* saveBtn;

	void InitUI();
	void OnImageSelected(wxFileDirPickerEvent& event);
	void OnClear(wxCommandEvent& event);

public:
	AddStationary(wxWindow* parent);
	void Clear();
	Stationary GetStationaryFromPanel();
	bool ValidateStationary();
	void IntoFile(char* fileName);
};

