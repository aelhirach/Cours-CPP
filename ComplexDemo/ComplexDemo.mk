##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ComplexDemo
ConfigurationName      :=Debug
WorkspacePath          := "D:\users\mattens\Mes documents\Ann_1516\isib\cpp\5IN0301\workspace"
ProjectPath            := "D:\users\mattens\Mes documents\Ann_1516\isib\cpp\5IN0301\syllabus\ComplexDemo"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=mattens
Date                   :=24/09/2015
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=C:/MinGW-4.8.1/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW-4.8.1/bin/g++.exe -shared -fPIC
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
ObjectsFileList        :="ComplexDemo.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW-4.8.1/bin/windres.exe
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
AR       := C:/MinGW-4.8.1/bin/ar.exe rcu
CXX      := C:/MinGW-4.8.1/bin/g++.exe
CC       := C:/MinGW-4.8.1/bin/gcc.exe
CXXFLAGS := -pedantic -Wall -g $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW-4.8.1/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/src_Complex.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_ComplexDemo.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/src_Complex.cpp$(ObjectSuffix): src/Complex.cpp $(IntermediateDirectory)/src_Complex.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/users/mattens/Mes documents/Ann_1516/isib/cpp/5IN0301/syllabus/ComplexDemo/src/Complex.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Complex.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Complex.cpp$(DependSuffix): src/Complex.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Complex.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Complex.cpp$(DependSuffix) -MM "src/Complex.cpp"

$(IntermediateDirectory)/src_Complex.cpp$(PreprocessSuffix): src/Complex.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Complex.cpp$(PreprocessSuffix) "src/Complex.cpp"

$(IntermediateDirectory)/src_ComplexDemo.cpp$(ObjectSuffix): src/ComplexDemo.cpp $(IntermediateDirectory)/src_ComplexDemo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/users/mattens/Mes documents/Ann_1516/isib/cpp/5IN0301/syllabus/ComplexDemo/src/ComplexDemo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ComplexDemo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ComplexDemo.cpp$(DependSuffix): src/ComplexDemo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ComplexDemo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ComplexDemo.cpp$(DependSuffix) -MM "src/ComplexDemo.cpp"

$(IntermediateDirectory)/src_ComplexDemo.cpp$(PreprocessSuffix): src/ComplexDemo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ComplexDemo.cpp$(PreprocessSuffix) "src/ComplexDemo.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


