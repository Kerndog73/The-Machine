//
//  radioactivity sprite writer.hpp
//  The Machine
//
//  Created by Indi Kernick on 8/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef radioactivity_sprite_writer_hpp
#define radioactivity_sprite_writer_hpp

#include "quad writer.hpp"

class RadioactivitySpriteWriter final : public QuadWriter {
public:
  RadioactivitySpriteWriter(TextureID, std::shared_ptr<ECS::Registry>, std::shared_ptr<Spritesheet>);

  void writeQuads(QuadIter, Frame) const override;
  TextureID getTexture() const override;
  size_t count() const override;

private:
  TextureID tex;
  std::shared_ptr<ECS::Registry> registry;
  std::shared_ptr<Spritesheet> sheet;
};

#endif
