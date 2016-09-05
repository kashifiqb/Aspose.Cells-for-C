﻿/* The unique head file needed to be included */
#include "Aspose.Cells.h"
#include <iostream>
using namespace std;
/*In order to use DLL we have to import Aspose.Cells.lib first*/
#pragma comment(lib,"Aspose.Cells.lib")  

static StringPtr sourcePath = new String("Data\\");
static StringPtr dataDir_LoadingAndSaving = sourcePath->StringAppend(new String("Loading-and-Saving\\"));
static StringPtr dataDir_Worksheets = sourcePath->StringAppend(new String("Worksheets\\"));
static StringPtr dataDir_RowsAndColumns = sourcePath->StringAppend(new String("Rows-and-Columns\\"));

 #define EXPECT_TRUE(condition) \
		if (condition) printf("--%s,line:%d->Ok--\n", __FUNCTION__, __LINE__); \
			 else  printf("--%s,line:%d->>>>Failed!!!!<<<<--\n", __FUNCTION__, __LINE__);

/*	
	We only list a few case to explain how to test Aspose.Cells Lib,
	Of course this affirmative is not comprehensive.
*/

/*
	To avoid memory leak£¬we import smart pointer "intrusive_ptr" of boost,
	for example,if allocate memory for workbook, we use "intrusive_ptr<Workbook> workbook = new Workbook()"
	rather than  "Workbook *workbook = new Workbook()", if so, we no longer need use "delete".
*/
#pragma region "General"
void OpenSaveTest()
{
	// ExStart:OpenSaveTest
	// Instantiate a Workbook object and open an Excel file
	intrusive_ptr<Workbook>  workbook = new Workbook(sourcePath->StringAppend(new String("SG-L-AllInd-Hd+Co-Rank32.xlsx")));
	workbook->Save(sourcePath->StringAppend(new String("SG-L-AllInd-Hd+Co-Rank32_out_.xlsx")));
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(0);
	EXPECT_TRUE(workbook&&worksheet);
	// ExEnd:OpenSaveTest
}

void Font_Style_Test1()
{
	// ExStart:Font_Style_Test1
	// Instantiate a Workbook object and open an Excel file
	intrusive_ptr<Workbook> workbook = new Workbook(sourcePath->StringAppend(new String("spreads_ExcelTest.xls")));
	intrusive_ptr<Cells> cells = workbook->GetWorksheets()->GetIndexObject(0)->GetCells();
	// Get cell by name from cells collection
	intrusive_ptr<FontSetting>  chars = cells->GetCellByName(new String("A3"))->Characters(0, 19);
	chars->GetFont()->SetIsBold(true);
	EXPECT_TRUE(chars->GetFont()->IsBold());
	EXPECT_TRUE(chars->GetFont()->GetName()->Equals((StringPtr)new String("Courier New")));
	EXPECT_TRUE(chars->GetFont()->GetSize() == 8);
	// ExEnd:Font_Style_Test1
}
void Font_Style_Test2()
{
	// ExStart:Font_Style_Test2
	// Instantiate a Workbook object
	intrusive_ptr<Workbook> workbook = new Workbook();
	intrusive_ptr<Worksheet> sheet = workbook->GetWorksheets()->GetIndexObject(0);
	// Get cells from sheet
	intrusive_ptr<Cells> cells = sheet->GetCells();
	intrusive_ptr<Cell> cell = cells->GetIndexObject(6, 1);
	cell->PutValue(new String("06:42"), true);
	intrusive_ptr<Style> style = cell->GetStyle();
	style->SetNumber(20);
	cell->SetStyle(style);
	EXPECT_TRUE(cell->GetStringValue()->Equals((StringPtr) new String("6:42")));
	// ExEnd:Font_Style_Test2
}

void  Font_Style_Test3()
{
	// ExStart:Font_Style_Test3
	// Instantiate a Workbook object
	intrusive_ptr<Workbook> workbook = new Workbook();
	// Get cell by name from cells collection
	intrusive_ptr<Cell> cell = workbook->GetWorksheets()->GetIndexObject(0)->GetCells()->GetCellByName(new String("A1"));
	cell->PutValue((StringPtr) new String("Hello. I have Bold texts in blue without any italicized textthat isn't bold last stuff unformatted"));
	cell->Characters(15, 4)->GetFont()->SetIsBold(true);
	cell->Characters(29, 4)->GetFont()->SetColor(ColorTranslator::FromHtml(new String("blue")));
	cell->Characters(33, 16)->GetFont()->SetColor(ColorTranslator::FromHtml(new String("green")));
	cell->Characters(38, 3)->GetFont()->SetIsStrikeout(true);
	cell->Characters(46, 15)->GetFont()->SetIsBold(true);
	cell->Characters(46, 30)->GetFont()->SetIsItalic(true);
	workbook->Save(sourcePath->StringAppend(new String("Test_160131_out_.xls")));
	workbook = new Workbook(sourcePath->StringAppend(new String("Test_160131_out_.xls")));
	cell = workbook->GetWorksheets()->GetIndexObject(0)->GetCells()->GetCellByName(new String("A1"));
	intrusive_ptr<Array1D<FontSetting*>> chs = cell->GetCharacters();
	for (int i = 0; i < chs->Length(); i++)
	{
		intrusive_ptr<FontSetting> chars = chs->GetValue(i);
		if (chars->GetStartIndex() == 46)
		{
			EXPECT_TRUE(chars->GetLength() == 3);
			EXPECT_TRUE(chars->GetFont()->IsBold());
			EXPECT_TRUE(chars->GetFont()->IsItalic());
		}
	}
	// ExEnd:Font_Style_Test3
}

void AutofilterTest()
{
	// ExStart:AutofilterTest
	// Instantiate a Workbook object and open an Excel file
	intrusive_ptr<Workbook> workbook = new Workbook(sourcePath->StringAppend(new String("aa_filtre.xls")));
	intrusive_ptr<Worksheet> sheet = workbook->GetWorksheets()->GetIndexObject(0);
	sheet->GetAutoFilter()->SetRange(0, 0, 1);
	sheet->GetAutoFilter()->Filter(1, new String("Nom2"));
	sheet->GetAutoFilter()->Refresh();
	EXPECT_TRUE(workbook->GetWorksheets()->GetIndexObject(0)->GetCells()->GetRowHeight(3) == 0);
	EXPECT_TRUE(workbook->GetWorksheets()->GetIndexObject(0)->GetCells()->GetRowHeight(4) == 0);
	workbook->Save(sourcePath->StringAppend(new String("aa_filtre_out_.xls")));
	// ExEnd:AutofilterTest
}

void  ConditionalFormatTest1()
{
	// ExStart:ConditionalFormatTest1
	// Instantiate a Workbook object and open an Excel file
	intrusive_ptr<Workbook> wb = new Workbook(sourcePath->StringAppend(new String("CELLSJAVA41671.xlsx")));
	// Get cell by name from worksheet cells collection
	intrusive_ptr<Cell> cell = wb->GetWorksheets()->GetIndexObject(0)->GetCells()->GetCellByName(new String("U78"));
	intrusive_ptr<Style> style = cell->GetDisplayStyle();
	intrusive_ptr<Color> color = style->GetForegroundColor();
	intrusive_ptr<Color> a = style->GetForegroundColor();
	intrusive_ptr<Color> b = Color::FromArgb(192, 0, 0);
	EXPECT_TRUE((a->ToArgb() & 0xFFFFFF) == (b->ToArgb() & 0xFFFFFF));
	// ExEnd:ConditionalFormatTest1
}
void  ConditionalFormatTest2()
{
	// ExStart:ConditionalFormatTest2
	// Instantiate a Workbook object and open an Excel file
	intrusive_ptr<Workbook> workbook = new Workbook();
	intrusive_ptr<ConditionalFormattingCollection> cfs = workbook->GetWorksheets()->GetIndexObject(0)->GetConditionalFormattings();
	cfs->Add();
	cfs->GetIndexObject(0)->AddCondition(FormatConditionType_CellValue, OperatorType_Between, new String("2"), new String("5"));
	intrusive_ptr<CellArea> ca = new CellArea();
	ca->StartColumn = 0;
	ca->StartRow = 0;
	ca->EndColumn = 5;
	ca->EndRow = 3;
	cfs->GetIndexObject(0)->AddArea(ca);
	workbook->Save(sourcePath->StringAppend(new String("ConditionalFormatTest_001_out_.xls")));
	workbook = new Workbook(sourcePath->StringAppend(new String("ConditionalFormatTest_001_out_.xls")));
	cfs = workbook->GetWorksheets()->GetIndexObject(0)->GetConditionalFormattings();
	intrusive_ptr<FormatCondition> fc = cfs->GetIndexObject(0)->GetIndexObject(0);
	EXPECT_TRUE(fc->GetFormula1()->Equals(StringPtr(new String("2"))));
	EXPECT_TRUE(fc->GetFormula2()->Equals(StringPtr(new String("5"))));
	EXPECT_TRUE(fc->GetOperator() == OperatorType_Between);
	EXPECT_TRUE(cfs->GetIndexObject(0)->GetCellArea(0)->EndRow == 3);
	// ExEnd:ConditionalFormatTest2
}

void HyperlinkTest()
{
	// ExStart:HyperlinkTest
	// Instantiate a Workbook object
	intrusive_ptr<Workbook> w = new Workbook();
	// Get Hyperlinks
	intrusive_ptr<HyperlinkCollection> links = w->GetWorksheets()->GetIndexObject(0)->GetHyperlinks();
	// Add Hyperlink in hyperlink collection
	links->Add(new String("A1"), 1, 1, new String("www.aspose.com"));
	EXPECT_TRUE(w->GetWorksheets()->GetIndexObject(0)->GetCells()->GetIndexObject(new String("A1"))->GetStringValue()->Equals((StringPtr)new String("www.aspose.com")));
	w->GetWorksheets()->GetIndexObject(0)->GetCells()->GetIndexObject(new String("A1"))->PutValue((StringPtr) new String("sdfsdf"));
	EXPECT_TRUE(links->GetIndexObject(0)->GetTextToDisplay()->Equals((StringPtr)new String("sdfsdf")));
	// Saving the Excel file
	w->Save(sourcePath->StringAppend(new String("CELLSNET43900_out_.xlsx")));
	// ExEnd:HyperlinkTest
}
void PageSetupTest()
{
	// ExStart:PageSetupTest
	// Instantiate a Workbook object and open excel file
	intrusive_ptr<Workbook> workbook = new Workbook(sourcePath->StringAppend(new String("pagesetup2.xls")));
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(0);
	intrusive_ptr<PageSetup> pagesetup = worksheet->GetPageSetup();
	// Page
	EXPECT_TRUE(pagesetup->GetOrientation() == PageOrientationType_Portrait);
	EXPECT_TRUE(pagesetup->GetZoom() == 105);
	EXPECT_TRUE(pagesetup->GetPaperSize() == PaperSizeType_PaperA4);
	EXPECT_TRUE(pagesetup->GetFirstPageNumber() == 1);
	// Margins
	EXPECT_TRUE(pagesetup->GetCenterHorizontally());
	EXPECT_TRUE(pagesetup->GetCenterVertically());
	// Header/Footer
	EXPECT_TRUE(StringHelperPal::IsNullString(pagesetup->GetHeader(0)));// String("")
	EXPECT_TRUE(StringHelperPal::IsNullString(pagesetup->GetHeader(1)));
	EXPECT_TRUE(StringHelperPal::IsNullString(pagesetup->GetHeader(2)));
	EXPECT_TRUE(StringHelperPal::IsNullString(pagesetup->GetFooter(0)));
	EXPECT_TRUE(StringHelperPal::IsNullString(pagesetup->GetFooter(1)));
	EXPECT_TRUE(StringHelperPal::IsNullString(pagesetup->GetFooter(2)));
	// Sheet
	EXPECT_TRUE(pagesetup->GetPrintTitleRows()->Equals((StringPtr)new String("$1:$1")));
	EXPECT_TRUE(pagesetup->GetPrintGridlines());
	EXPECT_TRUE(!pagesetup->GetBlackAndWhite());
	EXPECT_TRUE(!pagesetup->GetDraft());
	EXPECT_TRUE(pagesetup->GetPrintHeadings());
	EXPECT_TRUE(pagesetup->GetPrintComments() == PrintCommentsType_PrintSheetEnd);
	EXPECT_TRUE(pagesetup->GetPrintErrors() == PrintErrorsType_PrintErrorsNA);
	EXPECT_TRUE(pagesetup->GetOrder() == PrintOrderType_OverThenDown);
	// ExEnd:PageSetupTest
}


void PivotTableDataTest()
{
	// ExStart:PivotTableDataTest
	// Instantiate a Workbook object
	intrusive_ptr<Workbook> wb = new Workbook();
	wb->GetWorksheets()->Add();
	intrusive_ptr<Worksheet> data = wb->GetWorksheets()->GetIndexObject(0);
	int row = 0;
	data->GetCells()->GetIndexObject(row, 0)->PutValue((StringPtr)new String("Customer"));
	data->GetCells()->GetIndexObject(row, 1)->PutValue((StringPtr)new String("Sku"));
	data->GetCells()->GetIndexObject(row, 2)->PutValue((StringPtr)new String("Qty"));
	intrusive_ptr<Random> r = new Random();
	for (row = 1; row < 50; row++)
	{
		data->GetCells()->GetIndexObject(row, 0)->PutValue(r->Next(3) > 1 ? (StringPtr)new String("Customer A") : (StringPtr)new String("Customer B"));
		data->GetCells()->GetIndexObject(row, 1)->PutValue(r->Next(3) > 1 ? (StringPtr)new String("Sku A") : (StringPtr)new String("Sku B"));
		data->GetCells()->GetIndexObject(row, 2)->PutValue(r->Next(1, 100));
	}
	intrusive_ptr<Worksheet> pivot = wb->GetWorksheets()->GetIndexObject(1);
	intrusive_ptr<PivotTable> pt = pivot->GetPivotTables()->GetIndexObject(pivot->GetPivotTables()->Add((StringPtr)new String("=Sheet1!A1:C50"), 0, 0, (StringPtr)new String("Test pivot")));
	pt->SetEnableWizard(true);
	pt->AddFieldToArea(PivotFieldType_Row, 0);
	pt->GetRowFields()->GetIndexObject(0)->SetIsAutoSubtotals(false);
	pt->AddFieldToArea(PivotFieldType_Row, 1);
	pt->GetRowFields()->GetIndexObject(1)->SetIsAutoSubtotals(false);
	pt->AddFieldToArea(PivotFieldType_Data, 2);
	pt->SetIsAutoFormat(true);
	pt->SetAutoFormatType(PivotTableAutoFormatType_Report5);
	pt->SetHasBlankRows(false);
	EXPECT_TRUE(pt->GetEnableWizard());
	EXPECT_TRUE(!pt->GetRowFields()->GetIndexObject(0)->IsAutoSubtotals());
	EXPECT_TRUE(!pt->GetRowFields()->GetIndexObject(1)->IsAutoSubtotals());
	EXPECT_TRUE(pt->IsAutoFormat());
	EXPECT_TRUE(!pt->HasBlankRows());
	// Saving the Excel file
	wb->Save(sourcePath->StringAppend(new String("Test_156592_out_.xls")));
	// ExEnd:PivotTableDataTest
}
void ListObjectTest()
{
	// ExStart:ListObjectTest
	// Instantiate a Workbook object and open excel file
	intrusive_ptr<Workbook> workbook = new Workbook(sourcePath->StringAppend(new String("CellsNet41046.xlsx")));
	intrusive_ptr<ListObject> listObject = workbook->GetWorksheets()->GetIndexObject(0)->GetListObjects()->GetIndexObject(0);
	listObject->ApplyStyleToRange();
	intrusive_ptr<Style> style = workbook->GetWorksheets()->GetIndexObject(0)->GetCells()->GetIndexObject(new String("A1"))->GetStyle();
	EXPECT_TRUE((style->GetForegroundColor()->ToArgb() & 0xFFFFFF) == (Color::FromArgb(79, 129, 189)->ToArgb() & 0xFFFFFF));
	workbook->GetWorksheets()->GetIndexObject(0)->GetListObjects()->RemoveAt(0);
	workbook = new Workbook(sourcePath->StringAppend(new String("CellsNet41046.xlsx")));
	listObject = workbook->GetWorksheets()->GetIndexObject(0)->GetListObjects()->GetIndexObject(0);
	listObject->ConvertToRange();
	style = workbook->GetWorksheets()->GetIndexObject(0)->GetCells()->GetIndexObject(new String("A1"))->GetStyle();
	EXPECT_TRUE((style->GetForegroundColor()->ToArgb() & 0xFFFFFF) == (Color::FromArgb(79, 129, 189)->ToArgb() & 0xFFFFFF));
	EXPECT_TRUE(workbook->GetWorksheets()->GetIndexObject(0)->GetListObjects()->GetCount() == 0);
	// ExEnd:ListObjectTest
}
void Chart()
{
	// ExStart:Chart
	// Instantiating a Workbook object
	intrusive_ptr<Workbook> workbook = new Workbook();

	// Adding a new worksheet to the Excel object
	int sheetIndex = workbook->GetWorksheets()->Add();

	// Obtaining the reference of the newly added worksheet by passing its sheet index
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(sheetIndex);

	// Adding a sample value to "A1" cell
	worksheet->GetCells()->GetCellByName(new String("A1"))->PutValue(50);

	// Adding a sample value to "A2" cell
	worksheet->GetCells()->GetCellByName(new String("A2"))->PutValue(50);

	// Adding a sample value to "A3" cell
	worksheet->GetCells()->GetCellByName(new String("A3"))->PutValue(50);

	// Adding a sample value to "B1" cell
	worksheet->GetCells()->GetCellByName(new String("B1"))->PutValue(50);

	// Adding a sample value to "B2" cell
	worksheet->GetCells()->GetCellByName(new String("B2"))->PutValue(50);

	// Adding a sample value to "B3" cell
	worksheet->GetCells()->GetCellByName(new String("B3"))->PutValue(50);
	//chart.NSeries.Add("A1:B3", true);
	// Saving the Excel file
	workbook->Save(sourcePath->StringAppend(new String("chart_out_.xls")));
	// ExEnd:Chart
}
void BuiltInProperties()
{
	// ExStart:BuiltInProperties
	// Instantiate a Workbook object and open an Excel file
	intrusive_ptr<Workbook> workbook = new Workbook(sourcePath->StringAppend(new String("book1.xls")));

	// Retrieve a list of all custom document properties of the Excel file
	intrusive_ptr<DocumentPropertyCollection> properties = workbook->GetWorksheets()->GetBuiltInDocumentProperties();


	for (int i = 0; i < properties->GetCount(); i++)
	{
		// Accessing a custom document property by using the property index
		intrusive_ptr<DocumentProperty> customProperty1 = properties->GetIndexObject(i);
		cout << customProperty1;
	}
	// ExEnd:BuiltInProperties
}
void CustomInProperties()
{
	// ExStart:CustomInProperties
	// Instantiate a Workbook object and open an Excel file
	intrusive_ptr<Workbook> workbook = new Workbook(sourcePath->StringAppend(new String("book1.xls")));

	// Retrieve a list of all custom document properties of the Excel file
	intrusive_ptr<DocumentPropertyCollection> properties = workbook->GetWorksheets()->GetCustomDocumentProperties();

	for (int i = 0; i < properties->GetCount(); i++)
	{
		// Accessing a custom document property by using the property index
		intrusive_ptr<DocumentProperty> customProperty1 = properties->GetIndexObject(i);
		cout << customProperty1;
	}
	// ExEnd:CustomInProperties
}
#pragma endregion

#pragma region "Loading and Saving"
void OpenFileUsingPath()
{
	// ExStart:OpenFileUsingPath
	// Instantiate a Workbook object and open an Excel file using its file path
	intrusive_ptr<Workbook>  workbook = new Workbook(dataDir_LoadingAndSaving->StringAppend(new String("Book1.xlsx")));
	printf("\nWorkbook opened successfully using path!");
	// ExEnd:OpenFileUsingPath
}
void OpenFileUsingStream()
{
	// ExStart:OpenFileUsingStream
	// Create a Stream object
	intrusive_ptr<FileStream>  fstream = new FileStream(dataDir_LoadingAndSaving->StringAppend(new String("Book1.xlsx")), FileMode_Open);

	// Creating a Workbook object, open the file from a Stream object
	intrusive_ptr<Workbook>  workbook = new Workbook(fstream);
	printf("\nWorkbook opened successfully using stream!");
	fstream->Close();
	// ExEnd:OpenFileUsingStream
}
void OpenVisibleSheetOnly()
{
	// ExStart:OpenVisibleSheetOnly
	// Instantiate LoadOptions specified by the LoadFormat
	intrusive_ptr<LoadOptions>  loadOptions7 = new LoadOptions(LoadFormat_Xlsx);
	// Set the LoadDataOption
	intrusive_ptr<LoadDataOption>  dataOption = new LoadDataOption();
	
	dataOption->SetOnlyVisibleWorksheet(true);

	// Only data and formatting should be loaded.
	loadOptions7->SetLoadDataAndFormatting(true);

	// Specify the LoadDataOption
	loadOptions7->SetLoadDataOptions(dataOption);

	// Create a Workbook object and opening the file from its path
	intrusive_ptr<Workbook>  wb = new Workbook(dataDir_LoadingAndSaving->StringAppend(new String("Book1.xlsx")), loadOptions7);	
	printf("\nVisible sheet loaded successfully!");	
	// ExEnd:OpenVisibleSheetOnly
}
void SavingToStream()
{
	// ExStart:SavingToStream
	// Instantiate a Workbook object and open an Excel file using its file path
	intrusive_ptr<Workbook>  workbook = new Workbook(dataDir_LoadingAndSaving->StringAppend(new String("Book1.xlsx")));

	intrusive_ptr<FileStream> stream = new FileStream(dataDir_LoadingAndSaving->StringAppend(new String("SavingToStream_out_.xlsx")), FileMode_CreateNew);
	
	workbook->Save(stream, new XlsSaveOptions(SaveFormat_Xlsx));
	stream->Close();
	printf("\nFile saved successfully to a stream!");
	// ExEnd:SavingToStream
}
void SavingToSomeLocation()
{
	// ExStart:SavingToSomeLocation
	// Instantiate a Workbook object and open an Excel file using its file path
	intrusive_ptr<Workbook>  workbook = new Workbook(dataDir_LoadingAndSaving->StringAppend(new String("Book1.xlsx")));

	// Save in Excel 97 � 2003 format
	workbook->Save(dataDir_LoadingAndSaving->StringAppend(new String("SavingToSomeLocation_out_.xls")));
	// OR
	workbook->Save(dataDir_LoadingAndSaving->StringAppend(new String("SavingToSomeLocation_out_.xls")), new XlsSaveOptions(SaveFormat_Excel97To2003));

	// Save in Excel2007 xlsx format
	workbook->Save(dataDir_LoadingAndSaving->StringAppend(new String("SavingToSomeLocation_out_.xlsx")), SaveFormat_Xlsx);

	// Save in Excel2007 xlsb format
	workbook->Save(dataDir_LoadingAndSaving->StringAppend(new String("SavingToSomeLocation_out_.xlsb")), SaveFormat_Xlsb);

	// Save in ODS format
	workbook->Save(dataDir_LoadingAndSaving->StringAppend(new String("SavingToSomeLocation_out_.ods")), SaveFormat_ODS);

	// Save in Pdf format
	workbook->Save(dataDir_LoadingAndSaving->StringAppend(new String("SavingToSomeLocation_out_.pdf")), SaveFormat_Pdf);

	// Save in Html format
	workbook->Save(dataDir_LoadingAndSaving->StringAppend(new String("SavingToSomeLocation_out_.html")), SaveFormat_Html);

	// Save in SpreadsheetML format
	workbook->Save(dataDir_LoadingAndSaving->StringAppend(new String("SavingToSomeLocation_out_.xml")), SaveFormat_SpreadsheetML);
	// ExEnd:SavingToSomeLocation
}
#pragma endregion

#pragma region "Rows and Columns"

void SetRowHeight()
{

	// ExStart:SetRowHeight
	// Creating a file stream containing the Excel file to be opened
	intrusive_ptr<FileStream> fstream = new FileStream(dataDir_RowsAndColumns->StringAppend(new String("Book1.xlsx")), FileMode_Open);

	// Instantiating a Workbook object and opening the Excel file through the file stream
	intrusive_ptr<Workbook> workbook = new Workbook(fstream);

	// Accessing the first worksheet in the Excel file
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(0);

	// Setting the height of the second row to 13
	worksheet->GetCells()->SetRowHeight(1, 13);

	// Save the Excel file.
	workbook->Save(dataDir_RowsAndColumns->StringAppend(new String("SetRowHeight_out_.xls")));

	// Closing the file stream to free all resources
	fstream->Close();
	// ExEnd:SetRowHeight
}

void SettingAllRowsHeight()
{

	// ExStart:SettingAllRowsHeight
	// Creating a file stream containing the Excel file to be opened
	intrusive_ptr<FileStream> fstream = new FileStream(dataDir_RowsAndColumns->StringAppend(new String("Book1.xlsx")), FileMode_Open);

	// Instantiating a Workbook object and opening the Excel file through the file stream
	intrusive_ptr<Workbook> workbook = new Workbook(fstream);

	// Accessing the first worksheet in the Excel file
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(0);

	// Setting the height of all rows in the worksheet to 15
	worksheet->GetCells()->SetStandardHeight(15);

	// Save the Excel file.
	workbook->Save(dataDir_RowsAndColumns->StringAppend(new String("SettingAllRowsHeight_out_.xls")));

	// Closing the file stream to free all resources
	fstream->Close();
	// ExEnd:SettingAllRowsHeight
}
void SettingColumWidth()
{

	// ExStart:SettingColumWidth
	// Creating a file stream containing the Excel file to be opened
	intrusive_ptr<FileStream> fstream = new FileStream(dataDir_RowsAndColumns->StringAppend(new String("Book1.xlsx")), FileMode_Open);

	// Instantiating a Workbook object and opening the Excel file through the file stream
	intrusive_ptr<Workbook> workbook = new Workbook(fstream);

	// Accessing the first worksheet in the Excel file
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(0);

	// Setting the width of the second column to 17.5
	worksheet->GetCells()->SetColumnWidth(1, 17.5);

	// Save the Excel file.
	workbook->Save(dataDir_RowsAndColumns->StringAppend(new String("SettingColumWidth_out_.xls")));

	// Closing the file stream to free all resources
	fstream->Close();
	// ExEnd:SettingColumWidth
}
void SettingWidthOfAllColumns()
{

	// ExStart:SettingWidthOfAllColumns
	// Creating a file stream containing the Excel file to be opened
	intrusive_ptr<FileStream> fstream = new FileStream(dataDir_RowsAndColumns->StringAppend(new String("Book1.xlsx")), FileMode_Open);

	// Instantiating a Workbook object and opening the Excel file through the file stream
	intrusive_ptr<Workbook> workbook = new Workbook(fstream);

	// Accessing the first worksheet in the Excel file
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(0);

	// Setting the width of all columns in the worksheet to 20.5
	worksheet->GetCells()->SetStandardWidth(20.5);

	// Save the Excel file.
	workbook->Save(dataDir_RowsAndColumns->StringAppend(new String("SettingWidthOfAllColumns_out_.xls")));

	// Closing the file stream to free all resources
	fstream->Close();
	// ExEnd:SettingWidthOfAllColumns
}
void CopyRows()
{
	// ExStart:CopyRows
	// Instantiating a Workbook object and opening the Excel file through the path
	intrusive_ptr<Workbook> workbook = new Workbook(dataDir_RowsAndColumns->StringAppend(new String("Book1.xlsx")));

	// Accessing the first worksheet in the Excel file
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(0);

	// Copy the second row with data, formattings, images and drawing objects to the 16th row in the worksheet.
	worksheet->GetCells()->CopyRow(worksheet->GetCells(), 1, 15);

	// Save the Excel file.
	workbook->Save(dataDir_RowsAndColumns->StringAppend(new String("CopyRows_out_.xls")));
	// ExEnd:CopyRows
}
void CopyColumns()
{
	// ExStart:CopyColumns
	// Instantiating a Workbook object and opening the Excel file through the path
	intrusive_ptr<Workbook> workbook = new Workbook(dataDir_RowsAndColumns->StringAppend(new String("Book1.xlsx")));

	// Accessing the first worksheet in the Excel file
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(0);

	// Copy the first column from the first worksheet of the first workbook into the first worksheet of the second workbook.
	worksheet->GetCells()->CopyColumn(worksheet->GetCells(), 0, 2);

	// Save the Excel file.
	workbook->Save(dataDir_RowsAndColumns->StringAppend(new String("CopyColumns_out_.xls")));
	// ExEnd:CopyColumns
}
void GroupRowsColumns()
{
	// ExStart:GroupRowsColumns
	// Creating a file stream containing the Excel file to be opened
	intrusive_ptr<FileStream> fstream = new FileStream(dataDir_RowsAndColumns->StringAppend(new String("Book1.xlsx")), FileMode_Open);

	// Instantiating a Workbook object and opening the Excel file through the file stream
	intrusive_ptr<Workbook> workbook = new Workbook(fstream);

	// Accessing the first worksheet in the Excel file
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(0);
	
	// Grouping first six rows and first three columns
	worksheet->GetCells()->GroupRows(0, 5, true);
	worksheet->GetCells()->GroupColumns(0, 2, true);

	// Save the Excel file.
	workbook->Save(dataDir_RowsAndColumns->StringAppend(new String("GroupRowsColumns_out_.xls")));

	// Closing the file stream to free all resources
	fstream->Close();
	// ExEnd:GroupRowsColumns
}
void SummaryRowBelow()
{
	// ExStart:SummaryRowBelow 
	// Instantiating a Workbook object and opening the Excel file through the path
	intrusive_ptr<Workbook> workbook = new Workbook(dataDir_RowsAndColumns->StringAppend(new String("Book1.xlsx")));

	// Accessing the first worksheet in the Excel file
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(0);

	// Grouping first six rows and first three columns
	worksheet->GetCells()->GroupRows(0, 5, true);
	worksheet->GetCells()->GroupColumns(0, 2, true);

	// Setting SummaryRowBelow property to false
	worksheet->GetOutline()->SummaryRowBelow = false;

	// Save the Excel file.
	workbook->Save(dataDir_RowsAndColumns->StringAppend(new String("SummaryRowBelow_out_.xls")));
	// ExEnd:SummaryRowBelow 
}
void SummaryColumnRight()
{
	// ExStart:SummaryColumnRight  
	// Instantiating a Workbook object and opening the Excel file through the path
	intrusive_ptr<Workbook> workbook = new Workbook(dataDir_RowsAndColumns->StringAppend(new String("Book1.xlsx")));

	// Accessing the first worksheet in the Excel file
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(0);

	// Grouping first six rows and first three columns
	worksheet->GetCells()->GroupRows(0, 5, true);
	worksheet->GetCells()->GroupColumns(0, 2, true);

	worksheet->GetOutline()->SummaryColumnRight = true;

	// Save the Excel file.
	workbook->Save(dataDir_RowsAndColumns->StringAppend(new String("SummaryColumnRight_out_.xls")));
	// ExEnd:SummaryColumnRight  
}
void UngroupRowsAndColumns()
{
	// ExStart:UngroupRowsAndColumns  
	// Creating a file stream containing the Excel file to be opened
	intrusive_ptr<FileStream> fstream = new FileStream(dataDir_RowsAndColumns->StringAppend(new String("Book1.xlsx")), FileMode_Open);

	// Instantiating a Workbook object and opening the Excel file through the file stream
	intrusive_ptr<Workbook> workbook = new Workbook(fstream);

	// Accessing the first worksheet in the Excel file
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(0);

	// UnGrouping first six rows and first three columns
	worksheet->GetCells()->UngroupRows(0, 5);
	worksheet->GetCells()->UngroupColumns(0, 2);

	// Save the Excel file.
	workbook->Save(dataDir_RowsAndColumns->StringAppend(new String("UngroupRowsAndColumns_out_.xls")));
	// Closing the file stream to free all resources
	fstream->Close();
	// ExEnd:UngroupRowsAndColumns  
}
void InsertRow()
{
	// ExStart:InsertRow  
	// Creating a file stream containing the Excel file to be opened
	intrusive_ptr<FileStream> fstream = new FileStream(dataDir_RowsAndColumns->StringAppend(new String("Book1.xlsx")), FileMode_Open);

	// Instantiating a Workbook object and opening the Excel file through the file stream
	intrusive_ptr<Workbook> workbook = new Workbook(fstream);

	// Accessing the first worksheet in the Excel file
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(0);

	// Inserting a row into the worksheet at 3rd position
	worksheet->GetCells()->InsertRow(2);

	// Save the Excel file.
	workbook->Save(dataDir_RowsAndColumns->StringAppend(new String("InsertRow_out_.xls")));
	// Closing the file stream to free all resources
	fstream->Close();
	// ExEnd:InsertRow  
}
void InsertMultipleRows()
{
	// ExStart:InsertMultipleRows  
	// Creating a file stream containing the Excel file to be opened
	intrusive_ptr<FileStream> fstream = new FileStream(dataDir_RowsAndColumns->StringAppend(new String("Book1.xlsx")), FileMode_Open);

	// Instantiating a Workbook object and opening the Excel file through the file stream
	intrusive_ptr<Workbook> workbook = new Workbook(fstream);

	// Accessing the first worksheet in the Excel file
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(0);

	// Inserting 10 rows into the worksheet starting from 3rd row
	worksheet->GetCells()->InsertRows(2, 10);

	// Save the Excel file.
	workbook->Save(dataDir_RowsAndColumns->StringAppend(new String("InsertMultipleRows_out_.xls")));
	// Closing the file stream to free all resources
	fstream->Close();
	// ExEnd:InsertMultipleRows  
}
void DeleteMultipleRows()
{
	// ExStart:DeleteMultipleRows  
	// Creating a file stream containing the Excel file to be opened
	intrusive_ptr<FileStream> fstream = new FileStream(dataDir_RowsAndColumns->StringAppend(new String("Book1.xlsx")), FileMode_OpenOrCreate);

	// Instantiating a Workbook object and opening the Excel file through the file stream
	intrusive_ptr<Workbook> workbook = new Workbook(fstream);

	// Accessing the first worksheet in the Excel file
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(0);

	// Deleting 10 rows from the worksheet starting from 3rd row
	worksheet->GetCells()->DeleteRows(2, 10);

	// Save the Excel file.
	workbook->Save(dataDir_RowsAndColumns->StringAppend(new String("DeleteMultipleRows_out_.xls")));
	// Closing the file stream to free all resources
	fstream->Close();
	// ExEnd:DeleteMultipleRows  
}
void InsertColumn()
{
	// ExStart:InsertColumn  
	// Creating a file stream containing the Excel file to be opened
	intrusive_ptr<FileStream> fstream = new FileStream(dataDir_RowsAndColumns->StringAppend(new String("Book1.xlsx")), FileMode_Open);

	// Instantiating a Workbook object and opening the Excel file through the file stream
	intrusive_ptr<Workbook> workbook = new Workbook(fstream);

	// Accessing the first worksheet in the Excel file
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(0);

	// Inserting a column into the worksheet at 2nd position
	worksheet->GetCells()->InsertColumn(1);

	// Save the Excel file.
	workbook->Save(dataDir_RowsAndColumns->StringAppend(new String("InsertColumn_out_.xls")));
	// Closing the file stream to free all resources
	fstream->Close();
	// ExEnd:InsertColumn  
}
void DeleteColumn()
{
	// ExStart:DeleteColumn  
	// Creating a file stream containing the Excel file to be opened
	intrusive_ptr<FileStream> fstream = new FileStream(dataDir_RowsAndColumns->StringAppend(new String("Book1.xlsx")), FileMode_Open);

	// Instantiating a Workbook object and opening the Excel file through the file stream
	intrusive_ptr<Workbook> workbook = new Workbook(fstream);

	// Accessing the first worksheet in the Excel file
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(0);

	// Deleting a column from the worksheet at 2nd position
	worksheet->GetCells()->DeleteColumn(4);

	// Save the Excel file.
	workbook->Save(dataDir_RowsAndColumns->StringAppend(new String("DeleteColumn_out_.xls")));
	// Closing the file stream to free all resources
	fstream->Close();
	// ExEnd:DeleteColumn  
}
#pragma endregion

#pragma region "Worksheets"
void CopyWorksheetsWithinWorkbook()
{
	// ExStart:CopyWorksheetsWithinWorkbook
	// Instantiate a Workbook object and open an Excel file
	intrusive_ptr<Workbook>  workbook = new Workbook(dataDir_Worksheets->StringAppend(new String("Book1.xlsx")));

	// Create a Worksheets object with reference to the sheets of the Workbook.
	intrusive_ptr<WorksheetCollection> sheets = workbook->GetWorksheets();

	// Copy data to a new sheet from an existing sheet within the Workbook.
	sheets->AddCopy(new String("Sheet1"));

	// Save the Excel file.
	workbook->Save(dataDir_Worksheets->StringAppend(new String("CopyWorksheetsWithinWorkbook_out_.xls")));
	printf("\nWorksheet copied successfully with in a workbook!");
	// ExEnd:CopyWorksheetsWithinWorkbook
}
void MoveWorksheetsWithinWorkbook()
{
	// ExStart:MoveWorksheetsWithinWorkbook
	// Instantiate a Workbook object and open an Excel file
	intrusive_ptr<Workbook>  workbook = new Workbook(dataDir_Worksheets->StringAppend(new String("Book1.xlsx")));

	// Create a Worksheets object with reference to the sheets of the Workbook and get the first worksheet.
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(0);

	// Move the first sheet to the third position in the workbook.
	worksheet->MoveTo(2);

	// Save the Excel file.
	workbook->Save(dataDir_Worksheets->StringAppend(new String("MoveWorksheetsWithinWorkbook_out_.xls")));
	printf("\nWorksheet moved successfully with in a workbook!");
	// ExEnd:MoveWorksheetsWithinWorkbook
}
void AddingWorksheetsToNewExcelFile()
{
	// ExStart:AddingWorksheetsToNewExcelFile
	// Instantiate a Workbook object
	intrusive_ptr<Workbook>  workbook = new Workbook();

	// Adding a new worksheet to the Workbook object
	int i = workbook->GetWorksheets()->Add();

	// Obtaining the reference of the newly added worksheet by passing its sheet index
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(i);

	// Setting the name of the newly added worksheet
	worksheet->SetName(new String("My Worksheet"));

	// Save the Excel file.
	workbook->Save(dataDir_Worksheets->StringAppend(new String("AddingWorksheetsToNewExcelFile_out_.xls")));
	printf("\nWorksheet moved successfully with in a workbook!");
	// ExEnd:AddingWorksheetsToNewExcelFile
}

void AccessingWorksheetsUsingIndex()
{
	// ExStart:AccessingWorksheetsUsingIndex
	// Creating a file stream containing the Excel file to be opened
	intrusive_ptr<FileStream> fstream = new FileStream(dataDir_Worksheets->StringAppend(new String("Book1.xlsx")), FileMode_Open);

	// Instantiating a Workbook object and opening the Excel file through the file stream
	intrusive_ptr<Workbook> workbook = new Workbook(fstream);

	// Accessing a worksheet using its index and Get cell by name from worksheet cells collection
	intrusive_ptr<Cell> cell = workbook->GetWorksheets()->GetIndexObject(0)->GetCells()->GetCellByName(new String("A1"));	
	// Closing the file stream to free all resources
	fstream->Close();
	// ExEnd:AccessingWorksheetsUsingIndex
}
void RemoveWorksheetsUsingIndex()
{
	// ExStart:RemoveWorksheetsUsingIndex
	// Creating a file stream containing the Excel file to be opened
	intrusive_ptr<FileStream> fstream = new FileStream(dataDir_Worksheets->StringAppend(new String("Book1.xlsx")), FileMode_Open);

	// Instantiating a Workbook object and opening the Excel file through the file stream
	intrusive_ptr<Workbook> workbook = new Workbook(fstream);

	// Removing a worksheet using its sheet index
	workbook->GetWorksheets()->RemoveAt(0);

	// Save the Excel file.
	workbook->Save(dataDir_Worksheets->StringAppend(new String("RemoveWorksheetsUsingIndex_out_.xls")));
	// Closing the file stream to free all resources
	fstream->Close();
	// ExEnd:RemoveWorksheetsUsingIndex
}
void AddPageBreaks()
{
	// ExStart:AddPageBreaks
	// Instantiating a Workbook object
	intrusive_ptr<Workbook> workbook  = new Workbook();

	// Add a page break at cell Y30
	workbook->GetWorksheets()->GetIndexObject(0)->GetHorizontalPageBreaks()->Add(new String("Y30"));
	workbook->GetWorksheets()->GetIndexObject(0)->GetVerticalPageBreaks()->Add(new String("Y30"));

	// Save the Excel file.
	workbook->Save(dataDir_Worksheets->StringAppend(new String("AddPageBreaks_out_.xls")));
	// ExEnd:AddPageBreaks
}
void ClearAllPageBreaks()
{
	// ExStart:ClearAllPageBreaks
	// Instantiating a Workbook object
	intrusive_ptr<Workbook> workbook = new Workbook();

	// Clearing all page breaks
	workbook->GetWorksheets()->GetIndexObject(0)->GetHorizontalPageBreaks()->Clear();
	workbook->GetWorksheets()->GetIndexObject(0)->GetVerticalPageBreaks()->Clear();

	// Save the Excel file.
	workbook->Save(dataDir_Worksheets->StringAppend(new String("ClearAllPageBreaks_out_.xls")));
	// ExEnd:ClearAllPageBreaks
}
void RemoveSpecificPageBreaks()
{
	// ExStart:RemoveSpecificPageBreaks
	// Instantiate a Workbook object and open an Excel file
	intrusive_ptr<Workbook>  workbook = new Workbook(dataDir_Worksheets->StringAppend(new String("PageBreaks.xls")));

	// Removing a specific page break
	workbook->GetWorksheets()->GetIndexObject(0)->GetHorizontalPageBreaks()->RemoveAt(0);
	workbook->GetWorksheets()->GetIndexObject(0)->GetVerticalPageBreaks()->RemoveAt(0);

	// Save the Excel file.
	workbook->Save(dataDir_Worksheets->StringAppend(new String("RemoveSpecificPageBreaks_out_.xls")));
	// ExEnd:RemoveSpecificPageBreaks
}
void EnableNormalView()
{
	// ExStart:EnableNormalView
	// Creating a file stream containing the Excel file to be opened
	intrusive_ptr<FileStream> fstream = new FileStream(dataDir_Worksheets->StringAppend(new String("Book1.xlsx")), FileMode_Open);

	// Instantiating a Workbook object and opening the Excel file through the file stream
	intrusive_ptr<Workbook> workbook = new Workbook(fstream);

	// Accessing a worksheet using its index
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(0);

	// Displaying the worksheet in page break preview
	worksheet->SetIsPageBreakPreview(true);

	// Saving the modified Excel file
	workbook->Save(dataDir_Worksheets->StringAppend(new String("EnableNormalView_out_.xls")));

	// Closing the file stream to free all resources
	fstream->Close();
	// ExEnd:EnableNormalView
}
void SetZoomFactor()
{
	// ExStart:SetZoomFactor
	// Creating a file stream containing the Excel file to be opened
	intrusive_ptr<FileStream> fstream = new FileStream(dataDir_Worksheets->StringAppend(new String("Book1.xlsx")), FileMode_Open);

	// Instantiating a Workbook object and opening the Excel file through the file stream
	intrusive_ptr<Workbook> workbook = new Workbook(fstream);

	// Accessing a worksheet using its index
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(0);

	// Setting the zoom factor of the worksheet to 75
	worksheet->SetZoom(75);

	// Saving the modified Excel file
	workbook->Save(dataDir_Worksheets->StringAppend(new String("SetZoomFactor_out_.xls")));

	// Closing the file stream to free all resources
	fstream->Close();
	// ExEnd:SetZoomFactor
}
void FreezePanes()
{
	// ExStart:FreezePanes
	// Creating a file stream containing the Excel file to be opened
	intrusive_ptr<FileStream> fstream = new FileStream(dataDir_Worksheets->StringAppend(new String("Book1.xlsx")), FileMode_Open);

	// Instantiating a Workbook object and opening the Excel file through the file stream
	intrusive_ptr<Workbook> workbook = new Workbook(fstream);

	// Accessing a worksheet using its index
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(0);

	// Applying freeze panes settings
	worksheet->FreezePanes(3, 2, 3, 2);

	// Saving the modified Excel file
	workbook->Save(dataDir_Worksheets->StringAppend(new String("FreezePanes_out_.xls")));

	// Closing the file stream to free all resources
	fstream->Close();
	// ExEnd:FreezePanes
}
void SplitPanes()
{
	// ExStart:SplitPanes
	// Instantiating a Workbook object and opening the Excel file through the path
	intrusive_ptr<Workbook> workbook = new Workbook(dataDir_Worksheets->StringAppend(new String("Book1.xlsx")));

	// Accessing a worksheet using its index
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(0);

    // Set the active cell
    worksheet->SetActiveCell(new String("A20"));

	// Split the worksheet window
	worksheet->Split();

	// Saving the modified Excel file
	workbook->Save(dataDir_Worksheets->StringAppend(new String("FreezePanes_out_.xls")));
	// ExEnd:SplitPanes
}
void RemovingPanes()
{
	// ExStart:RemovingPanes
	// Instantiating a Workbook object and opening the Excel file through the path
	intrusive_ptr<Workbook> workbook = new Workbook(dataDir_Worksheets->StringAppend(new String("Book1.xlsx")));

	// Accessing a worksheet using its index
	intrusive_ptr<Worksheet> worksheet = workbook->GetWorksheets()->GetIndexObject(0);

	// Set the active cell
	worksheet->SetActiveCell(new String("A20"));

	// Split the worksheet window
	worksheet->RemoveSplit();

	// Saving the modified Excel file
	workbook->Save(dataDir_Worksheets->StringAppend(new String("RemovingPanes_out_.xls")));
	// ExEnd:RemovingPanes
}
#pragma endregion

int main(int argc, char** argv)
{	
	
	printf("Open main.cpp. \nIn main() method uncomment the example that you want to run.\n");
	printf("=====================================================\n");
	
	//// =====================================================
	//// =====================================================
	//// General
	//// =====================================================
	//// =====================================================

	//Font_Style_Test1();
	//Font_Style_Test2();
	//Font_Style_Test3();
	//AutofilterTest();
	//ConditionalFormatTest1();
	//ConditionalFormatTest2();
	//HyperlinkTest();
	//PageSetupTest();
	//PivotTableDataTest();
	//ListObjectTest();	
	//Chart();
	//BuiltInProperties();

	//// =====================================================
	//// =====================================================
	//// Loading and Saving
	//// =====================================================
	//// =====================================================

	//OpenFileUsingPath();
	//OpenFileUsingStream();
	//OpenVisibleSheetOnly();
	//SavingToStream();
	//SavingToSomeLocation();

	//// =====================================================
	//// =====================================================
	//// Worksheets
	//// =====================================================
	//// =====================================================

	//CopyWorksheetsWithinWorkbook();
	//MoveWorksheetsWithinWorkbook();
	//AddingWorksheetsToNewExcelFile();
	//AccessingWorksheetsUsingIndex();	
	//RemoveWorksheetsUsingIndex();
	//AddPageBreaks();
	//RemoveSpecificPageBreaks();
	//ClearAllPageBreaks();
	//EnableNormalView();
	//SetZoomFactor();	
	//FreezePanes();
	//SplitPanes();
	//RemovingPanes();

	//// =====================================================
	//// =====================================================
	//// Rows and Columns
	//// =====================================================
	//// =====================================================

	//SetRowHeight();
	//SettingAllRowsHeight();
	//SettingColumWidth();
	//SettingWidthOfAllColumns();
	//CopyRows();
	//CopyColumns();
	//GroupRowsColumns();
	//SummaryRowBelow();
	//SummaryColumnRight();
	//UngroupRowsAndColumns();
	//InsertRow();
	//InsertMultipleRows();
	//DeleteMultipleRows();
	//InsertColumn();
	//DeleteColumn();
		
	// Stop before exiting
	printf("\n\nProgram Finished. Press any key to exit....");
	getchar();	
}
