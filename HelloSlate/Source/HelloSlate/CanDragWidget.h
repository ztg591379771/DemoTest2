// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Framework/SlateDelegates.h"
#include "MyAssetData.h"
#include "Engine.h"
/**
 * 
 */
class HELLOSLATE_API SCanDragWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCanDragWidget)
	{}
	//SLATE_EVENT(FOnDragDetected, OnDragDetected)
	//SLATE_EVENT(FOnTableRowDragEnter, OnDragEnter)
	//SLATE_EVENT(FOnTableRowDragLeave, OnDragLeave)
	//SLATE_EVENT(FOnTableRowDrop, OnDrop)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	virtual FReply OnDragDetected(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override
	{
		if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
		{
			return FReply::Handled().DetectDrag(SharedThis(this), EKeys::LeftMouseButton);
		}
		return FReply::Unhandled();
	}



protected:


};
