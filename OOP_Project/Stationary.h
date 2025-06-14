#pragma once

#include "Product.h"
#include"MyString.h"
#include <wx/mstream.h>


class Stationary : public Product
{
private:
	MyString stationaryType;
	MyString stationaryBrand;
	MyString stationaryColor;

public:
	Stationary();
	Stationary(const Stationary& other);
	Stationary& operator=(const Stationary& other);
	Stationary(const MyString& id, const MyString& name,
		const MyString& desc, int price,
		wxImage*& image, const MyString& type,
		const MyString brand, const MyString& color);

	// void writeToFile(fstream& fout) const override;
	// void readFromFile(fstream& fin) const override;

	//setter
	void SetPrice(int price) override;
	void SetProductDescription(const MyString& desc) override;
	void SetStationaryType(const MyString& type);
	void SetStationaryBrand(const MyString& brand);
	void SetStationaryColor(const MyString& color);
	void SetProductName(const MyString& name)override;
	void SetProductID(const MyString& id) override;
	void SetProductImage(const wxImage& image)override;

	//getter
	MyString getProductID() const  override;
	MyString getProductName() const override;
	MyString getProductCategory() const override;
	MyString getDescription() const override;
	int getPrice() const override;
	wxImage* GetProductImage() const override;


	MyString getStationaryType() const;
	MyString getStationaryBrand() const;
	MyString getStationaryColor() const;

	// display not defined yet
	void Display() const override;


	void WriteProductIntoFile(std::ofstream& fout) override;
	void ReadProductFromFile(std::ifstream& fin) override;

};

