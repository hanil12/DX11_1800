#pragma once
class PlanetScene : public Scene
{
public:
	PlanetScene();
	virtual ~PlanetScene();

	virtual void Update() override;
	virtual void Render() override;
private:
	shared_ptr<Planet> _sun;
	shared_ptr<Planet> _earth;
	shared_ptr<Planet> _moon;

	shared_ptr<Transform> _sunTrans;
	shared_ptr<Transform> _earthTrans;
};

