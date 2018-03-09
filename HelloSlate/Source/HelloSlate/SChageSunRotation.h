// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "SlateBasics.h"
#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
/**
 * 
 */

DECLARE_DELEGATE_OneParam(FOnFloatValueChanged, float);
DECLARE_DELEGATE_OneParam(FOnCheckBoxStateChanged, bool);

class HELLOSLATE_API SChageSunRotation : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SChageSunRotation)
	{}
	SLATE_EVENT(FOnFloatValueChanged, OnFloatValueChanged)
	SLATE_EVENT(FOnCheckBoxStateChanged, OnCheckBoxStateChanged)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
private:
	
	/**
	  ��Checkbox��״̬�ı�ʱ���ı�Controller��״̬
	  �ö���һ���������Ĵ��� ����ִ��
	*/
	void OnCheckStateChenged(ECheckBoxState NewState);
	/**
	  �������ֵ�ı�ʱ���ı�Controller��ֵ��
	  �ö���һ���������Ĵ��� ����ִ��
	*/
	void OnValueChanged(float NewValue);

	/** �ı�̫���ǶȵĻ��� */
	TSharedPtr<SSlider> SunRotationSlider;

	TSharedPtr<SCheckBox>  SunRotationCheckBox;


private:
	
	FOnFloatValueChanged OnFloatValueChanged;

	FOnCheckBoxStateChanged OnCheckBoxStateChanged;
};
