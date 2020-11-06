##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ListStrings
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/rzouk/Documents/2eMasterC++
ProjectPath            :=C:/Users/rzouk/Documents/2eMasterC++/ListStrings
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=rzouk
Date                   :=04/12/2016
CodeLitePath           :="C:/Program Files (x86)/CodeLite"
LinkerName             :=C:/TDM-GCC-32/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-32/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
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
ObjectsFileList        :="ListStrings.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-32/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./../InOut/src 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)./../InOut/Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-32/bin/ar.exe rcu
CXX      := C:/TDM-GCC-32/bin/g++.exe
CC       := C:/TDM-GCC-32/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-32/bin/as.exe


##
## User defined environment variables
##
Objects0=$(IntermediateDirectory)/list.cpp$(ObjectSuffix) $(IntermediateDirectory)/algo.cpp$(ObjectSuffix) $(IntermediateDirectory)/ListStringsTest.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/list.cpp$(ObjectSuffix): list.cpp $(IntermediateDirectory)/list.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/rzouk/Documents/2eMasterC++/ListStrings/list.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/list.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/list.cpp$(DependSuffix): list.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/list.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/list.cpp$(DependSuffix) -MM list.cpp

$(IntermediateDirectory)/list.cpp$(PreprocessSuffix): list.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/list.cpp$(PreprocessSuffix)list.cpp

$(IntermediateDirectory)/algo.cpp$(ObjectSuffix): algo.cpp $(IntermediateDirectory)/algo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/rzouk/Documents/2eMasterC++/ListStrings/algo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/algo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/algo.cpp$(DependSuffix): algo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/algo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/algo.cpp$(DependSuffix) -MM algo.cpp

$(IntermediateDirectory)/algo.cpp$(PreprocessSuffix): algo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/algo.cpp$(PreprocessSuffix)algo.cpp

$(IntermediateDirectory)/ListStringsTest.cpp$(ObjectSuffix): ListStringsTest.cpp $(IntermediateDirectory)/ListStringsTest.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/rzouk/Documents/2eMasterC++/ListStrings/ListStringsTest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ListStringsTest.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ListStringsTest.cpp$(DependSuffix): ListStringsTest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ListStringsTest.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ListStringsTest.cpp$(DependSuffix) -MM ListStringsTest.cpp

$(IntermediateDirectory)/ListStringsTest.cpp$(PreprocessSuffix): ListStringsTest.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ListStringsTest.cpp$(PreprocessSuffix)ListStringsTest.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


