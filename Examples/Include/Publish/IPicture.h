#pragma once
#include "System/Object.h"
#include "System/Int32.h"
#include "System/Drawing/Color.h"
#include "System/Double.h"
#include "System/Array1D.h"
#include "System/Byte.h"
#include "System/String.h"
#include "System/Drawing/Imaging/ImageFormat.h"
#include "IShape.h"

namespace Aspose{
namespace Cells{
namespace Drawing{
			/// <summary>
			/// Encapsulates the object that represents a single picture in a spreadsheet.
			/// </summary>
	class ASPOSE_CELLS_API IPicture : virtual public Aspose::Cells::Drawing::IShape
	{
		public:
			/// <summary>
			/// Moves the picture to a specified location.
			/// </summary>
			/// <param name="upperLeftRow" >Upper left row index.</param>
			/// <param name="upperLeftColumn" >Upper left column index.</param>
			 virtual void Move(Aspose::Cells::System::Int32 upperLeftRow , Aspose::Cells::System::Int32 upperLeftColumn)=0;
			/// <summary>
			/// Gets the original height of the picture.
			/// </summary>
			 virtual Aspose::Cells::System::Int32 GetOriginalHeight()=0;
			/// <summary>
			/// Gets the original width of the picture.
			/// </summary>
			 virtual Aspose::Cells::System::Int32 GetOriginalWidth()=0;
			/// <summary>
			/// Represents the <see cref="System.Drawing.Color" />
			///  of the border line of a picture.
			/// </summary>
			 virtual intrusive_ptr<Aspose::Cells::System::Drawing::Color> GetBorderLineColor()=0;
			/// <summary>
			/// Represents the <see cref="System.Drawing.Color" />
			///  of the border line of a picture.
			/// </summary>
			 virtual void SetBorderLineColor(intrusive_ptr<Aspose::Cells::System::Drawing::Color> value)=0;
			/// <summary>
			/// Gets the weight of the border line of a picture in units of pt.
			/// </summary>
			 virtual Aspose::Cells::System::Double GetBorderWeight()=0;
			/// <summary>
			/// Sets the weight of the border line of a picture in units of pt.
			/// </summary>
			 virtual void SetBorderWeight(Aspose::Cells::System::Double value)=0;
			/// <summary>
			/// Gets the data of the picture.
			/// </summary>
			 virtual intrusive_ptr<Aspose::Cells::System::Array1D<Aspose::Cells::System::Byte>> GetData()=0;
			/// <summary>
			/// Gets the data of the picture.
			/// </summary>
			 virtual void SetData(intrusive_ptr<Aspose::Cells::System::Array1D<Aspose::Cells::System::Byte>> value)=0;
			/// <summary>
			/// Gets the path and name of the source file for the linked image. 
			/// </summary>
			/// <remarks>
			/// The default value is an empty string.
			/// If SourceFullName is not an empty string, the image is linked.
			/// If SourceFullName is not an empty string, but Data is null, then the image is linked and not stored in the file.
			/// </remarks>
			 virtual intrusive_ptr<Aspose::Cells::System::String> GetSourceFullName()=0;
			/// <summary>
			/// Sets the path and name of the source file for the linked image. 
			/// </summary>
			/// <remarks>
			/// The default value is an empty string.
			/// If SourceFullName is not an empty string, the image is linked.
			/// If SourceFullName is not an empty string, but Data is null, then the image is linked and not stored in the file.
			/// </remarks>
			 virtual void SetSourceFullName(intrusive_ptr<Aspose::Cells::System::String> value)=0;
			/// <summary>
			/// Gets the data of the formula.
			/// </summary>
			 virtual intrusive_ptr<Aspose::Cells::System::String> GetFormula()=0;
			/// <summary>
			/// Sets the data of the formula.
			/// </summary>
			 virtual void SetFormula(intrusive_ptr<Aspose::Cells::System::String> value)=0;
			/// <summary>
			/// True indicates that the size of the ole object will be auto changed as the size of snapshop of the embedded content
			/// when the ole object is activated.
			/// </summary>
			 virtual bool IsAutoSize()=0;
			/// <summary>
			/// True indicates that the size of the ole object will be auto changed as the size of snapshop of the embedded content
			/// when the ole object is activated.
			/// </summary>
			 virtual void SetAutoSize(bool value)=0;
			/// <summary>
			/// Returns true if the OleObject is linked
			/// </summary>
			 virtual bool IsLink()=0;
			/// <summary>
			/// Returns true if the OleObject is linked
			/// </summary>
			 virtual void SetLink(bool value)=0;
			/// <summary>
			/// Gets whether dynamic data exchange
			/// </summary>
			 virtual bool IsDynamicDataExchange()=0;
			/// <summary>
			/// Sets whether dynamic data exchange
			/// </summary>
			 virtual void SetDynamicDataExchange(bool value)=0;
			/// <summary>
			/// True if the specified object is displayed as an icon 
			/// and the image will not be auto changed.
			/// </summary>
			 virtual bool GetDisplayAsIcon()=0;
			/// <summary>
			/// True if the specified object is displayed as an icon 
			/// and the image will not be auto changed.
			/// </summary>
			 virtual void SetDisplayAsIcon(bool value)=0;
			/// <summary>
			/// Gets the image format of the picture.
			/// </summary>
			 virtual intrusive_ptr<Aspose::Cells::System::Drawing::Imaging::ImageFormat> GetImageFormat()=0;
			/// <summary>
			/// Gets the original height of picture, in unit of centimeters.
			/// </summary>
			 virtual Aspose::Cells::System::Double GetOriginalHeightCM()=0;
			/// <summary>
			/// Gets the original width of picture, in unit of centimeters.
			/// </summary>
			 virtual Aspose::Cells::System::Double GetOriginalWidthCM()=0;
			/// <summary>
			/// Gets the original height of picture, in unit of inches.
			/// </summary>
			 virtual Aspose::Cells::System::Double GetOriginalHeightInch()=0;
			/// <summary>
			/// Gets the original width of picture, in unit of inches.
			/// </summary>
			 virtual Aspose::Cells::System::Double GetOriginalWidthInch()=0;

	};
}
}
}
