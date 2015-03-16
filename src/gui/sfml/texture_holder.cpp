#include <SFML/Graphics.hpp>
#include <cassert>
#include "gui/sfml/texture_holder.hpp"

namespace tetris {
namespace sfml {
    
void texture_holder::load(textures::ID id, const std::string& filename)
{
    std::unique_ptr<sf::Texture> texture(new sf::Texture());
    if(!texture->loadFromFile(filename))
    {
        throw std::runtime_error("texture_holder::load - failed to load " + filename);
    }
    
    auto inserted = texture_map_.insert(std::make_pair(id, std::move(texture)));
    assert(inserted.second);
}

sf::Texture& texture_holder::get(textures::ID id)
{
    auto result = texture_map_.find(id);
    return *result->second;
}

} // namespace sfml
} // namespace tetris