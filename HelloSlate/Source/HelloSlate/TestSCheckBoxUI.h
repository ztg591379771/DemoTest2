// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
/**
*
*/
struct MyInfo
{
	MyInfo(FText InDisplayName, FName InHandle) :DisPlayName(InDisplayName), UniqueHandle(InHandle) {}

	FText DisPlayName;

	FName UniqueHandle;

};

class HELLOSLATE_API STestSCheckBoxUI : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(STestSCheckBoxUI)
	{}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
private:
	//创建一个选择框控件
	TSharedRef< SWidget > CreateMyInfoTap(const MyInfo& Info);

	//当选项的状态改变时
	void OnPlacementTabChanged(ECheckBoxState NewState, FName CategoryName);

	//获得选项的状态
	ECheckBoxState GetPlacementTabCheckedState(FName CategoryName) const;

	//根据选项改变边界的颜色
	const FSlateBrush* PlacementGroupBorderImage(FName CategoryName) const;

	//当前选中的选项的名字
	FName ActiveTabName;

	//是否需要更新左侧对应的内容
	bool bNeedsUpdate;
	//
	FText GetDynamicText() const;
	//
	TMap<FName, MyInfo> MapInfo;
};
