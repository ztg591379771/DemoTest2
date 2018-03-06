// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class HelloSlateEditorTarget : TargetRules
{
	public HelloSlateEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
        ExtraModuleNames.Add("HelloSlate");
        //ExtraModuleNames.AddRange( new string[] { "HelloSlate" } );
        ExtraModuleNames.Add("MySQLSupport");
    }
}
