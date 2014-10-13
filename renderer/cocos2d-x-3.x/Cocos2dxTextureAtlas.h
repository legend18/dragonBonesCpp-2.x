﻿#ifndef __COCOS2DX_TEXTURE_ATLAS_H__
#define __COCOS2DX_TEXTURE_ATLAS_H__
#include "preDB.h"
#include "ITextureAtlas.h"
#include "DBTransform.h"
#include "CCTextureAtlas.h"
namespace dragonBones
{
    class DisplayObject;
    class TextureAtlasData;
    /**
     * The Cocos2dxTextureAtlas creates and manipulates TextureAtlas from starling.display.DisplayObject.
     */
    class Cocos2dxTextureAtlas : public ITextureAtlas
    {
    protected:
        TextureAtlasData *_textureAtlasRawData;

        // 名字与atlas里的quads索引的对应关系
        std::map<String , uint> _textureNames;
        cocos2d::TextureAtlas *textureAtlas;
    public:

        Cocos2dxTextureAtlas(TextureAtlasData *data);
        virtual ~Cocos2dxTextureAtlas();
        /**
         * The name of this ITextureAtlas.
         */
        virtual const String &getName();
        /**
         * Clean up resources.
         */
        virtual void dispose();
        /**
         * Get the specific region of the TextureAtlas occupied by assets defined by that name.
         * @param    name The name of the assets represented by that name.
         * @return Rectangle The rectangle area occupied by those assets.
         */
        virtual Rectangle getRegion(const String &name);

        // 获取顶点数据所在的Quad索引
        uint getQuadIndex(const String &name)
        {
            std::map<String , uint>::iterator iter = _textureNames.find(name);
            if(iter != _textureNames.end())
            {
                return iter->second;
            }
            else
            {
                return 0;
            }
        }

        cocos2d::TextureAtlas *getTextureAtlas()
        {
            return textureAtlas;
        }
        /**
         * Updates the transform of the display object
         * @param    matrix
         * @param    transform
         */
        void updateTransform(DisplayObject *displayObject ,Matrix &matrix, DBTransform &transform);

        void updateColor(DisplayObject *displayObject ,
            Number aOffset, 
            Number rOffset, 
            Number gOffset, 
            Number bOffset, 
            Number aMultiplier, 
            Number rMultiplier, 
            Number gMultiplier, 
            Number bMultiplier
            );

    };
};
#endif // __COCOS2DX_TEXTURE_ATLAS_H__
