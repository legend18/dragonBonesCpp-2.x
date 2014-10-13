#ifndef __PRE_DB_H__
#define __PRE_DB_H__

#include "BytesType.h"
#include "DBGeometry.h"

#define DB_SAFE_DELETE(p)            do { if(p) { delete (p); (p) = 0; } } while(0)

//#define USE_QUICK_COCOS2DX// uncomment to enable quick-cocos2d-x support
#define COCOS2D_3X

#ifdef USE_QUICK_COCOS2DX
    #define CCNodeRGBA CCNode
    #define _displayedColor m_displayedColor
    #define _displayedOpacity m_displayedOpacity
#endif

#endif // __PRE_DB_H__
