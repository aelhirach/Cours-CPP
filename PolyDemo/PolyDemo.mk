##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=PolyDemo
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/rzouk/Documents/2eMasterC++
ProjectPath            :=C:/Users/rzouk/Documents/2eMasterC++/syllabus/PolyDemo
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=rzouk
Date                   :=22/09/2016
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
ObjectsFileList        :="PolyDemo.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
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
Objects0=$(IntermediateDirectory)/src_poly.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_PolyDemo.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/src_poly.cpp$(ObjectSuffix): src/poly.cpp $(IntermediateDirectory)/src_poly.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/rzouk/Documents/2eMasterC++/syllabus/PolyDemo/src/poly.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_poly.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_poly.cpp$(DependSuffix): src/poly.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_poly.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_poly.cpp$(DependSuffix) -MM "src/poly.cpp"

$(IntermediateDirectory)/src_poly.cpp$(PreprocessSuffix): src/poly.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_poly.cpp$(PreprocessSuffix) "src/poly.cpp"

$(IntermediateDirectory)/src_PolyDemo.cpp$(ObjectSuffix): src/PolyDemo.cpp $(IntermediateDirectory)/src_PolyDemo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/rzouk/Documents/2eMasterC++/syllabus/PolyDemo/src/PolyDemo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_PolyDemo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_PolyDemo.cpp$(DependSuffix): src/PolyDemo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_PolyDemo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_PolyDemo.cpp$(DependSuffix) -MM "src/PolyDemo.cpp"

$(IntermediateDirectory)/src_PolyDemo.cpp$(PreprocessSuffix): src/PolyDemo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_PolyDemo.cpp$(PreprocessSuffix) "src/PolyDemo.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


