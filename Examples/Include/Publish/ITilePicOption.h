#pragma once
#include "System/Object.h"
#include "System/Double.h"

namespace Aspose {
	namespace Cells {
		namespace Drawing {
			enum MirrorType;
			enum RectangleAlignmentType;
		}
	}
}
namespace Aspose{
namespace Cells{
namespace Drawing{
			/// <summary>
			/// Represents tile picture as texture.
			/// </summary>
	class ASPOSE_CELLS_API ITilePicOption : public Aspose::Cells::System::Object
	{
		public:
			/// <summary>
			/// Gets the X offset for tiling picture.
			/// </summary>
			 virtual Aspose::Cells::System::Double GetOffsetX()=0;
			/// <summary>
			/// Sets the X offset for tiling picture.
			/// </summary>
			 virtual void SetOffsetX(Aspose::Cells::System::Double value)=0;
			/// <summary>
			/// Gets the Y offset for tiling picture.
			/// </summary>
			 virtual Aspose::Cells::System::Double GetOffsetY()=0;
			/// <summary>
			/// Sets the Y offset for tiling picture.
			/// </summary>
			 virtual void SetOffsetY(Aspose::Cells::System::Double value)=0;
			/// <summary>
			/// Gets the X scale for tiling picture.
			/// </summary>
			 virtual Aspose::Cells::System::Double GetScaleX()=0;
			/// <summary>
			/// Sets the X scale for tiling picture.
			/// </summary>
			 virtual void SetScaleX(Aspose::Cells::System::Double value)=0;
			/// <summary>
			/// Gets the Y scale for tiling picture.
			/// </summary>
			 virtual Aspose::Cells::System::Double GetScaleY()=0;
			/// <summary>
			/// Sets the Y scale for tiling picture.
			/// </summary>
			 virtual void SetScaleY(Aspose::Cells::System::Double value)=0;
			/// <summary>
			/// Gets the mirror type for tiling.
			/// </summary>
			 virtual Aspose::Cells::Drawing::MirrorType GetMirrorType()=0;
			/// <summary>
			/// Sets the mirror type for tiling.
			/// </summary>
			 virtual void SetMirrorType(Aspose::Cells::Drawing::MirrorType value)=0;
			/// <summary>
			/// Gets the alignment for tiling.
			/// </summary>
			 virtual Aspose::Cells::Drawing::RectangleAlignmentType GetAlignmentType()=0;
			/// <summary>
			/// Sets the alignment for tiling.
			/// </summary>
			 virtual void SetAlignmentType(Aspose::Cells::Drawing::RectangleAlignmentType value)=0;

	};
}
}
}
