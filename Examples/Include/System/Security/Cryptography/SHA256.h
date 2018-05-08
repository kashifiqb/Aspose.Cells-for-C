#ifndef _SYSTEM_SECURITY_CRYPTOGRAPHY_SHA256_H_
#define _SYSTEM_SECURITY_CRYPTOGRAPHY_SHA256_H_

#include "System/String.h"
#include "System/Security/Cryptography/HashAlgorithm.h"
#ifdef _DEBUG
#include "System/Console.h"
#endif
using namespace Aspose::Cells::System;

namespace Aspose {
	namespace Cells {
		namespace System {
			namespace Security {
				namespace Cryptography {

					class ASPOSE_CELLS_API SHA256 : public HashAlgorithm  //to do
					{
					public:
						static intrusive_ptr<SHA256> Create(){
#ifdef _DEBUG
							Console::WriteLine(NEW String("SHA256->Create() Not Supported!!!"));
#endif	
							return NULL; }
						static intrusive_ptr<SHA256> Create(intrusive_ptr<String> hashName){ 
#ifdef _DEBUG
							Console::WriteLine(NEW String("SHA256->Create() Not Supported!!!"));
#endif								
							
							return NULL; }
					protected:
						SHA256(){}


					};
				} // namespace Cryptography
			}	// namespace Security
		}	// namespace System
	}
}
#endif