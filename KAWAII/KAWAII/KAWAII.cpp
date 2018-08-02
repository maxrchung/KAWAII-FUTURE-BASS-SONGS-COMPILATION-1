#include "Storyboard.hpp"
#include "Time.hpp"

const auto pi = 3.1415f;
float dToR(float degrees) {
	return pi * degrees / 180.0f;
}

void applyMotion(Sprite* const sprite, const int startTime) {
	auto temp = Sprite();
	sprite->Loop(startTime, 100, {
		temp.Scale(0, 10000, 0.5f - 0.01, 0.5f + 0.01, Easing::SineInOut),
		temp.Scale(10000, 20000, 0.5f + 0.01, 0.5f - 0.01, Easing::SineInOut),
	});
	sprite->Loop(startTime, 100, {
		temp.Rotate(0, 8000, -dToR(1.5f), dToR(1.5f), Easing::SineInOut),
		temp.Rotate(8000, 16000, dToR(1.5f), -dToR(1.5f), Easing::SineInOut),
	});
	sprite->Loop(startTime, 100, {
		temp.MoveX(0, 4000, 2, -2, Easing::SineInOut),
		temp.MoveX(4000, 8000, -2, 2, Easing::SineInOut),
	});
	sprite->Loop(startTime, 100, {
		temp.MoveY(0, 6000, 2, -2, Easing::SineInOut),
		temp.MoveY(6000, 12000, -2, 2, Easing::SineInOut),
	});
}

int main() {
	const auto scale = 0.5f;
	const auto textPosition = -Vector2::ScreenSize / 2 + Vector2(10, 10);

	auto coco = Storyboard::CreateSprite("coco.jpg", Vector2::Zero, Layer::Background);
	applyMotion(coco, Time("09:21:251").ms);
	auto cocoText = Storyboard::CreateSprite("coco-text.png", textPosition, Layer::Background, Origin::BottomLeft);
	cocoText->Scale(Time("09:21:251").ms, Time("12:20:310").ms, scale, scale);

	auto horizon = Storyboard::CreateSprite("horizon.jpg", Vector2::Zero, Layer::Background);
	applyMotion(horizon, Time("06:15:495").ms);
	horizon->Fade(Time("09:21:251").ms, Time("09:27:651").ms, 1, 0, Easing::EasingIn);
	auto horizonText = Storyboard::CreateSprite("horizon-text.png", textPosition, Layer::Background, Origin::BottomLeft);
	horizonText->Scale(Time("06:15:495").ms, Time("06:15:495").ms, scale, scale);
	horizonText->Fade(Time("09:21:251").ms, Time("09:27:651").ms, 1, 0, Easing::EasingIn);

	auto surprise = Storyboard::CreateSprite("surprise.jpg", Vector2::Zero, Layer::Background);
	applyMotion(surprise, Time("03:18:661").ms);
	surprise->Fade(Time("06:15:495").ms, Time("06:19:131").ms, 1, 0, Easing::EasingIn);
	auto surpriseText = Storyboard::CreateSprite("surprise-text.png", textPosition, Layer::Background, Origin::BottomLeft);
	surpriseText->Scale(Time("03:18:661").ms, Time("03:18:661").ms, scale, scale);
	surpriseText->Fade(Time("06:15:495").ms, Time("06:19:131").ms, 1, 0, Easing::EasingIn);

	auto sunlight = Storyboard::CreateSprite("sunlight.jpg", Vector2::Zero, Layer::Background);
	applyMotion(sunlight, 0);
	sunlight->Fade(Time("03:18:661").ms, Time("03:22:411").ms, 1, 0, Easing::EasingIn);
	auto sunlightText = Storyboard::CreateSprite("sunlight-text.png", textPosition, Layer::Background, Origin::BottomLeft);
	sunlightText->Scale(0, 0, scale, scale);
	sunlightText->Fade(Time("03:18:661").ms, Time("03:22:411").ms, 1, 0, Easing::EasingIn);

	Storyboard::Write(R"(X:\osu!\Songs\824720 PLEEG, jeonghyeon & cute girls doing cute things - KAWAII FUTURE BASS SONGS COMPILATION #1\PLEEG, jeonghyeon & cute girls doing cute things - KAWAII FUTURE BASS SONGS COMPILATION #1 (neko-san da).osb)");

	return 0;
}