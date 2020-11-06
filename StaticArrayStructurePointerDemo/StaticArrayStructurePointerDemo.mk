##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=StaticArrayStructurePointerDemo
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/rzouk/Documents/2eMasterC++
ProjectPath            :=C:/Users/rzouk/Documents/2eMasterC++/syllabus/StaticArrayStructurePointerDemo
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=rzouk
Date                   :=15/09/2016
CodeLitePath           :="C:/Program Files (x86)/CodeLite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="StaticArrayStructurePointerDemo.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS := -pedantic -Wall -g $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
Objects0=$(IntermediateDirectory)/src_StaticArrayStructurePointerDemo.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_StaticArrayStructurePointerDemo.cpp$(ObjectSuffix): src/StaticArrayStructurePointerDemo.cpp $(IntermediateDirectory)/src_StaticArrayStructurePointerDemo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/rzouk/Documents/2eMasterC++/syllabus/StaticArrayStructurePointerDemo/src/StaticArrayStructurePointerDemo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_StaticArrayStructurePointerDemo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_StaticArrayStructurePointerDemo.cpp$(DependSuffix): src/StaticArrayStructurePointerDemo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_StaticArrayStructurePointerDemo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_StaticArrayStructurePointerDemo.cpp$(DependSuffix) -MM "src/StaticArrayStructurePointerDemo.cpp"

$(IntermediateDirectory)/src_StaticArrayStructurePointerDemo.cpp$(PreprocessSuffix): src/StaticArrayStructurePointerDemo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_StaticArrayStructurePointerDemo.cpp$(PreprocessSuffix) "src/StaticArrayStructurePointerDemo.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


