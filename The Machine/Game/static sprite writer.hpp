//
//  static sprite writer.hpp
//  The Machine
//
//  Created by Indi Kernick on 8/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef static_sprite_writer_hpp
#define static_sprite_writer_hpp

#include "quad writer.hpp"
#include "rendering helpers.hpp"
#include <entt/entity/registry.hpp>

class StaticSpriteWriter final : public QuadWriter {
public:
  StaticSpriteWriter(TextureID, std::shared_ptr<entt::registry>, std::shared_ptr<Sheet>);

  void writeQuads(QuadIter, Frame) const override;
  TextureID getTexture() const override;
  size_t count() const override;

private:
  TextureID tex;
  std::shared_ptr<entt::registry> registry;
  std::shared_ptr<Sheet> sheet;
};

#endif
