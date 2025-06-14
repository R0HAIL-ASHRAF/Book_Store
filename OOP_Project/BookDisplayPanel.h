#pragma once

#include <wx/wx.h>
#include <wx/statbmp.h>
#include <wx/sizer.h>
#include <wx/image.h>
#include <wx/statline.h>
#include "Book.h"
#include"IDs.h"


class BookDisplayPanel : public wxPanel
{
public:
    BookDisplayPanel(wxWindow* parent);

    void SetBookInfo(const Book& book);

private:
    // UI controls
    wxStaticText* m_productIdText;
    wxStaticText* m_productNameText;
    wxStaticText* m_authorText;
    wxStaticText* m_genreText;
    wxStaticText* m_publisherText;
    wxStaticText* m_yearText;
    wxStaticText* m_pagesText;
    wxStaticText* m_priceText;
    wxStaticText* m_languageText;
    wxStaticText* m_descriptionText;
    wxStaticText* m_noCoverText;
    wxStaticText* m_titleText;
    wxStaticBitmap* m_imagePreview;

    void CreateControls();
};
