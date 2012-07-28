/// Texture resource base class

#ifndef OD_GRAPHICS_HAL_TEXTURE_HPP
#define OD_GRAPHICS_HAL_TEXTURE_HPP

#include "DeviceResource.hpp"

namespace od {
namespace graphics {
namespace hal {

/// Texture resource base class.
/// Holds one texture.
class Texture : public DeviceResource
{
    public:
        struct TextureSize
        {
            ODuint16 width;
            ODuint16 height;

            TextureSize() :
                width(0),
                height(0)
            {}

            TextureSize(ODuint16 twidth, ODuint16 theight):
                width(twidth),
                height(theight)
            {}
        };

        /// Destructor
        virtual ~Texture();

        // TODO: Add texture data setting functions
        //       and define datatypes for parameters.

        /// Returns texture size.
        /// @return TextureSize struct containing size of texture.
        virtual const TextureSize& getTextureSize() const;

        /// Returns channel count.
        /// @return Channel count of texture.
        virtual ODuint8 getChannelCount() const;

        /// Returns amount of memory one channel takes in bytes.
        /// @return Bytes per channel
        virtual ODuint8 getBytesPerChannel() const;

        virtual ODuint32 getSize() const;

    protected:
        Texture();

    private:
        Texture(const Texture&);
        Texture& operator= (const Texture&);

        ODuint8 mChannelCount;
        ODuint8 mBytesPerChannel;
        TextureSize mTextureSize;
};

}
}
}

#endif /* OD_GRAPHICS_HAL_TEXTURE_HPP */
