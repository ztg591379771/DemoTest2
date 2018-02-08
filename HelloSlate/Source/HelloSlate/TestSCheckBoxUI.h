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
	//����һ��ѡ���ؼ�
	TSharedRef< SWidget > CreateMyInfoTap(const MyInfo& Info);

	//��ѡ���״̬�ı�ʱ
	void OnPlacementTabChanged(ECheckBoxState NewState, FName CategoryName);

	//���ѡ���״̬
	ECheckBoxState GetPlacementTabCheckedState(FName CategoryName) const;

	//����ѡ��ı�߽����ɫ
	const FSlateBrush* PlacementGroupBorderImage(FName CategoryName) const;

	//��ǰѡ�е�ѡ�������
	FName ActiveTabName;

	//�Ƿ���Ҫ��������Ӧ������
	bool bNeedsUpdate;
	//
	FText GetDynamicText() const;
	//
	TMap<FName, MyInfo> MapInfo;
};
