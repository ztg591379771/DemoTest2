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
	  当Checkbox的状态改变时，改变Controller的状态
	  得定义一个带参数的代理 用来执行
	*/
	void OnCheckStateChenged(ECheckBoxState NewState);
	/**
	  当滑块的值改变时，改变Controller的值。
	  得定义一个带参数的代理 用来执行
	*/
	void OnValueChanged(float NewValue);

	/** 改变太阳角度的滑块 */
	TSharedPtr<SSlider> SunRotationSlider;

	TSharedPtr<SCheckBox>  SunRotationCheckBox;


private:
	
	FOnFloatValueChanged OnFloatValueChanged;

	FOnCheckBoxStateChanged OnCheckBoxStateChanged;
};
