// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

using System.IO;

namespace UnrealBuildTool.Rules
{
    public class MySQLSupport : ModuleRules
    {
        public MySQLSupport(ReadOnlyTargetRules Target) : base(Target)
        {
            PrivateDependencyModuleNames.AddRange(
                new string[] {
                "Core",
                "CoreUObject",
                "Engine",
                }
            );
            RulesAssembly RA;
            FileReference CheckProjectFile;
            UProjectInfo.TryGetProjectForTarget("HelloSlate", out CheckProjectFile);
            RA = RulesCompiler.CreateProjectRulesAssembly(CheckProjectFile);
            FileReference FR = RA.GetModuleFileName(this.GetType().Name);
            string ModulePath = Path.GetDirectoryName(FR.CanonicalName);


            string ThirdPartyPath = Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty/"));                 // gets the ThirdParty folder directory path        
            string MySQLConnectorPath = ThirdPartyPath + "MySQL Connector.C6.1/";                                    // gets the MySQL Connector.C 6.1 folder path        
            string MySQLConnectorLibraryPath = MySQLConnectorPath + "lib/";                                          // gets the path of the lib folder        
            string MySQLConnectorIncludePath = MySQLConnectorPath + "include/";                                      // gets the path of the include folder        
            string MySQLConnectorImportLibraryName = Path.Combine(MySQLConnectorLibraryPath, "libmysql.lib");        // gets the file path and name of the libmysql.lib static import library        
            string MySQLConnectorDLLName = Path.Combine(MySQLConnectorLibraryPath, "libmysql.dll");                  // gets the file path and name of libmysql.dll        
            if (!File.Exists(MySQLConnectorImportLibraryName))                                                       // check to ensure the static import lib can be located, or else we'll be in trouble        
            {
                throw new BuildException(string.Format("{0} could not be found.", MySQLConnectorImportLibraryName));        // log an error message explaining what went wrong if not found        
            }
            if (!File.Exists(MySQLConnectorDLLName))                                                                 // check to make sure the dll can be located or else we'll be in trouble        
            {
                throw new BuildException(string.Format("{0} could not be found.", MySQLConnectorDLLName));           // log an error message explaining what went wrong if not found        
            }

            PublicIncludePaths.Add(MySQLConnectorIncludePath);                                                       // add the "include" folder to our dependencies. I've chosen PrivateIncludePaths since I hide the mysql headers from external code        
            PublicLibraryPaths.Add(MySQLConnectorLibraryPath);                                                       // add the "lib" folder to our dependencies        
            PublicAdditionalLibraries.Add(MySQLConnectorImportLibraryName);                                          // add libmysql.lib static import library as a dependency        
            PublicDelayLoadDLLs.Add(MySQLConnectorDLLName);                                                          // add libmysql.dll as a dll    
            RuntimeDependencies.Add(new RuntimeDependency("$(ProjectDir)/Binaries/Win64/libmysql.dll"));             // 自动添加libmysql.dll到指定的打包目录中
        }
    }
}
