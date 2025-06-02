#pragma once

#include<wx/wx.h>
#include <wx/filepicker.h>
#include <wx/statline.h>
#include <filesystem>
#include "Book.h"


class AddBook : public wxPanel
{
private:

	wxTextCtrl* m_productIdCtrl;
	wxTextCtrl* m_productNameCtrl;
	wxTextCtrl* m_authorCtrl;
	wxComboBox* m_genreCtrl;
	wxTextCtrl* m_publisherCtrl;
	wxTextCtrl* m_yearCtrl;
	wxTextCtrl* m_pagesCtrl;
	wxTextCtrl* m_descriptionCtrl;
	wxTextCtrl* m_priceCtrl;
	wxTextCtrl* m_languageCtrl;
	wxFilePickerCtrl* m_imagePicker;
	wxStaticBitmap* m_imagePreview;
	wxImage m_productImage;
	MyString m_imagePath;


	
	void InitUI();
	void OnImageSelected(wxFileDirPickerEvent& event);
	

public:
	AddBook(wxWindow* parent);
	void ClearForm();
	void OnSaveProduct(wxCommandEvent& event);

};

