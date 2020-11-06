##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ListNamesPrj
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/rzouk/Documents/2eMasterC++
ProjectPath            :=C:/Users/rzouk/Documents/2eMasterC++/syllabus/ListNamesPrj
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=rzouk
Date                   :=15/12/2016
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
ObjectsFileList        :="ListNamesPrj.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-32/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./../InOut/src 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)InOut 
ArLibs                 :=  "InOut" 
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
Objects0=$(IntermediateDirectory)/algo.cpp$(ObjectSuffix) $(IntermediateDirectory)/list.cpp$(ObjectSuffix) $(IntermediateDirectory)/ListNamesTest.cpp$(ObjectSuffix) $(IntermediateDirectory)/name.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/algo.cpp$(ObjectSuffix): algo.cpp $(IntermediateDirectory)/algo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/rzouk/Documents/2eMasterC++/syllabus/ListNamesPrj/algo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/algo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/algo.cpp$(DependSuffix): algo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/algo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/algo.cpp$(DependSuffix) -MM algo.cpp

$(IntermediateDirectory)/algo.cpp$(PreprocessSuffix): algo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/algo.cpp$(PreprocessSuffix)algo.cpp

$(IntermediateDirectory)/list.cpp$(ObjectSuffix): list.cpp $(IntermediateDirectory)/list.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/rzouk/Documents/2eMasterC++/syllabus/ListNamesPrj/list.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/list.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/list.cpp$(DependSuffix): list.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/list.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/list.cpp$(DependSuffix) -MM list.cpp

$(IntermediateDirectory)/list.cpp$(PreprocessSuffix): list.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/list.cpp$(PreprocessSuffix)list.cpp

$(IntermediateDirectory)/ListNamesTest.cpp$(ObjectSuffix): ListNamesTest.cpp $(IntermediateDirectory)/ListNamesTest.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/rzouk/Documents/2eMasterC++/syllabus/ListNamesPrj/ListNamesTest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ListNamesTest.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ListNamesTest.cpp$(DependSuffix): ListNamesTest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ListNamesTest.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ListNamesTest.cpp$(DependSuffix) -MM ListNamesTest.cpp

$(IntermediateDirectory)/ListNamesTest.cpp$(PreprocessSuffix): ListNamesTest.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ListNamesTest.cpp$(PreprocessSuffix)ListNamesTest.cpp

$(IntermediateDirectory)/name.cpp$(ObjectSuffix): name.cpp $(IntermediateDirectory)/name.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/rzouk/Documents/2eMasterC++/syllabus/ListNamesPrj/name.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/name.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/name.cpp$(DependSuffix): name.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/name.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/name.cpp$(DependSuffix) -MM name.cpp

$(IntermediateDirectory)/name.cpp$(PreprocessSuffix): name.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/name.cpp$(PreprocessSuffix)name.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


