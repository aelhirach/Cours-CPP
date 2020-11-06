##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ListStringsPrj2016
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/rzouk/Documents/2eMasterC++
ProjectPath            :=C:/Users/rzouk/Documents/2eMasterC++/syllabus/ListStringsPrj2016
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
ObjectsFileList        :="ListStringsPrj2016.txt"
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
Objects0=$(IntermediateDirectory)/up_ListStringsPrj_algo.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_ListStringsPrj_list.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_ListStringsPrj_ListStringsTest.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/up_ListStringsPrj_algo.cpp$(ObjectSuffix): ../ListStringsPrj/algo.cpp $(IntermediateDirectory)/up_ListStringsPrj_algo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/rzouk/Documents/2eMasterC++/syllabus/ListStringsPrj/algo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_ListStringsPrj_algo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_ListStringsPrj_algo.cpp$(DependSuffix): ../ListStringsPrj/algo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_ListStringsPrj_algo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_ListStringsPrj_algo.cpp$(DependSuffix) -MM ../ListStringsPrj/algo.cpp

$(IntermediateDirectory)/up_ListStringsPrj_algo.cpp$(PreprocessSuffix): ../ListStringsPrj/algo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_ListStringsPrj_algo.cpp$(PreprocessSuffix)../ListStringsPrj/algo.cpp

$(IntermediateDirectory)/up_ListStringsPrj_list.cpp$(ObjectSuffix): ../ListStringsPrj/list.cpp $(IntermediateDirectory)/up_ListStringsPrj_list.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/rzouk/Documents/2eMasterC++/syllabus/ListStringsPrj/list.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_ListStringsPrj_list.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_ListStringsPrj_list.cpp$(DependSuffix): ../ListStringsPrj/list.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_ListStringsPrj_list.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_ListStringsPrj_list.cpp$(DependSuffix) -MM ../ListStringsPrj/list.cpp

$(IntermediateDirectory)/up_ListStringsPrj_list.cpp$(PreprocessSuffix): ../ListStringsPrj/list.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_ListStringsPrj_list.cpp$(PreprocessSuffix)../ListStringsPrj/list.cpp

$(IntermediateDirectory)/up_ListStringsPrj_ListStringsTest.cpp$(ObjectSuffix): ../ListStringsPrj/ListStringsTest.cpp $(IntermediateDirectory)/up_ListStringsPrj_ListStringsTest.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/rzouk/Documents/2eMasterC++/syllabus/ListStringsPrj/ListStringsTest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_ListStringsPrj_ListStringsTest.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_ListStringsPrj_ListStringsTest.cpp$(DependSuffix): ../ListStringsPrj/ListStringsTest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_ListStringsPrj_ListStringsTest.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_ListStringsPrj_ListStringsTest.cpp$(DependSuffix) -MM ../ListStringsPrj/ListStringsTest.cpp

$(IntermediateDirectory)/up_ListStringsPrj_ListStringsTest.cpp$(PreprocessSuffix): ../ListStringsPrj/ListStringsTest.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_ListStringsPrj_ListStringsTest.cpp$(PreprocessSuffix)../ListStringsPrj/ListStringsTest.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


