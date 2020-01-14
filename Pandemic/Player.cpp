#include "Player.h"
#include<iostream>
#include<algorithm>








void Player::FerryMove(City& nextCity) {

	if (this->GetCurentCity().FindNeibours(nextCity)) {
		this->SetCity(nextCity);
	}
	else {
		throw "1";
	}
}

void Player::FlightMove(City& nextCity) { 

	if (this->DiscardCard(nextCity)) {
		this->SetCity(nextCity);
	}
	else {
		throw "2";
	}


}

void Player::CharterMove(City& nextCity) { //City&

	if (this->DiscardCard(GetCurentCity())) {
		this->SetCity(nextCity);
	}
	else {
		throw "3";
	}

}

void Player::ShuttleMove(City& nextCity) { //City&

	if (this->GetCurentCity().GetResearchStationStatus() && nextCity.GetResearchStationStatus()) {
		this->SetCity(nextCity);
	}
	else {
		throw "4";
	}



}

void Player::BuildResearchStation() {
	if (this->DiscardCard(GetCurentCity())) {
		this->GetCurentCity().SetResearchStation(true);
	} 
	else{
		throw "5";
	}

}

void Player::TreatDesease(const EVirus virus) {

	if (GetCurentCity().GetNumberOfViruses(virus) != 0) {
		this->GetCurentCity().ReduceDiseases(virus);
	}
	else {
		throw "6";
	}

}

void Player::ShareKnowledge(const Player& p2,CityCard&& c1) {// Player obj, SelectedCard

	if (GetCurentCity().GetCityName() == p2.GetCurentCity().GetCityName())
	{
		this->AddCityCard(std::move(c1));
	}
	else {
		throw "7";
	}
}

void Player::DiscoverCure(EVirus virus) {

	auto count = 0;
	for (auto i = 0; i < GetNumOfCityCards(); ++i) {
		if (GetCard(i).GetVirus() == virus) {
			++count;
		}
	}
	if (count > 5) {
	
		for(auto i=0;i<GetNumOfCityCards();++i)
			if (GetCard(i).GetVirus() == virus) {
				if (count) {

					this->DeleteCard(GetCard(i));
				}
			}
		
	}
	else {
		throw "8";
	}
}
