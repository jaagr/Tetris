#ifndef TEXTURE_HOLDER_HPP
#define TEXTURE_HOLDER_HPP

namespace tetris {

namespace sfml {
    
namespace textures {
    enum ID { Background, Box };
} // namespace textures

class texture_holder
{
public:
    sf::Texture& get(textures::ID id);
    void load(textures::ID id, const std::string& filename);
    
private:
    std::map<textures::ID, std::unique_ptr<sf::Texture>> texture_map_;
};

} // namespace sfml
} // namespace tetris

#endif