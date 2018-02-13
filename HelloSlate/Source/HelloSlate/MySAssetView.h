// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
/**
 * 
 */

class HELLOSLATE_API SMySAssetView : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SMySAssetView)
	{}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

public:
	virtual FReply OnDrop(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent) override;
};
