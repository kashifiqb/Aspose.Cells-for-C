#ifndef _SYSTEM_DRAWING_RECTANGLEF_H_
#define _SYSTEM_DRAWING_RECTANGLEF_H_

#include "System/Object.h"
#include "System/Single.h"
#include "System/Drawing/PointF.h"
#include "System/Drawing/SizeF.h"
#include "System/String.h"

using namespace Aspose::Cells::System;

namespace Aspose { 
	namespace Cells { 
		namespace System {
			namespace Drawing {
				class ASPOSE_CELLS_API RectangleF : public Object
				{
					private:
						float x;
						float y;
						float width;
						float height;
					public:
						static intrusive_ptr<RectangleF> Empty;
						RectangleF(intrusive_ptr<PointF> location, intrusive_ptr<SizeF> size);
						RectangleF(Single x1, Single y1, Single width1, Single height1);
			
					public:
						Single GetHeight();
						void SetHeight(Single value);
						intrusive_ptr<PointF> GetLocation();
						void SetLocation(intrusive_ptr<PointF> point);
						intrusive_ptr<SizeF> GetSize();
						void SetSize(intrusive_ptr<SizeF> size);
						Single GetWidth();
						void SetWidth(Single value);
						Single GetX();
						void SetX(Single value);
						Single GetY();
						void SetY(Single value);
						Single GetLeft();
						Single GetRight();
						Single GetTop();
						Single GetBottom();
						bool IsEmpty();
						static intrusive_ptr<RectangleF> FromLTRB(Single left, Single top, Single right, Single bottom);
					public:
						bool Equals(ObjectPtr obj);
						int GetHashCode();
						StringPtr ToString();

				};
				typedef intrusive_ptr<RectangleF> RectangleFPtr;
			}
		}
	}
}
#endif//_SYSTEM_DRAWING_RECTANGLEF_H_