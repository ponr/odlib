#include "Texture.hpp"

namespace od {
namespace graphics {
namespace hal {

Texture::Texture() :
    DeviceResource(),
    mChannelCount(0),
    mBytesPerChannel(0),
    mTextureSize(0, 0)
{
}

Texture::~Texture()
{
}

const Texture::TextureSize& Texture::getTextureSize() const
{
    return mTextureSize;
}

ODuint8 Texture::getChannelCount() const
{
    return mChannelCount;
}

ODuint8 Texture::getBytesPerChannel() const
{
    return mBytesPerChannel;
}

ODuint32 Texture::getSize() const
{
    return (getChannelCount() * getBytesPerChannel()) *
        (getTextureSize().width * getTextureSize().height);
}


}
}
}
