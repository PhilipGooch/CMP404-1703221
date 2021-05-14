#pragma once
#include "state.h"

#include <graphics\sprite.h>
#include <platform/vita/graphics/texture_vita.h>
#include <graphics/mesh_instance.h>
#include <vector>

namespace gef
{
	class Platform;
	class InputManager;
	class AudioManager;
	class SpriteRenderer;
	class Renderer3D;
	class Font;
}
class StateMachine;
class Boid;

class MenuState : public State
{
public:
	MenuState(gef::Platform * platform,
			  gef::InputManager * input_manager,
			  gef::AudioManager * audio_manager,
			  gef::Renderer3D * renderer_3D,
			  gef::SpriteRenderer * sprite_renderer,
			  gef::Font * font,
			  StateMachine * state_machine);
	~MenuState();

protected:
	void Init() override;
	bool HandleInput() override;
	void Update(float delta_time) override;
	void Render() override;
	void Release() override;

	gef::Sprite background_sprite_;
	gef::Sprite indicator_sprite_;

	int selection_ = 0;

	gef::Texture* background_texture_;
	gef::Texture* indicator_texture_;

	gef::MeshInstance fish_body_blue_mesh_instance_;
	gef::MeshInstance fish_tail_blue_mesh_instance_;
	gef::MeshInstance fish_body_orange_mesh_instance_;
	gef::MeshInstance fish_tail_orange_mesh_instance_;

	int number_of_fishes_ = 2;
	std::vector<Boid*> fishes_;
};

