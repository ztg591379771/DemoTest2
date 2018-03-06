// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class HelloSlateTarget : TargetRules
{
	public HelloSlateTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
        ExtraModuleNames.Add("HelloSlate");
        //ExtraModuleNames.AddRange( new string[] { "HelloSlate" } );
        ExtraModuleNames.Add("MySQLSupport");
    }
}
