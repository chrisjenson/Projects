Project 3 Report
Chris Jenson, Mistee Branchek, and John Barry

Task: In this project you will gain hands-on experience working in a team to implement a dynamic programming algorithm, Edit Distance, from scratch. You will also build on your implementation to implement a basic Translation Memory Retrieval System. You will also gain experience in production of professional well documented software deliverables and reports.

Using the program (T1-T2):
Open the terminal
Navigate to the location where the “CJ_MB_JBProj3.tar.gz” file was downloaded
Ex. if downloaded to Downloads, enter “cd Downloads”
To extract the “CJ_MB_JBProj3.tar.gz” file, type "tar -zxvf CJ_MB_JBProj3.tar.gz"
Type “cd Project3” to enter the extracted folder named Project3 containing the Python code
Type “codeT12.py word1 word2”, and hit enter. Word1 is the first word you would like to use for edit distance and word2 is the second
The program will then output a possible minimum edit distance alignment and the edit distance

Using the program (T3-T5):
Open the terminal
Navigate to the location where the “CJ_MB_JBProj3.tar.gz” file was downloaded and extracted. If not already done, see instructions for T1-T2
Ex. if downloaded to Downloads, enter “cd Downloads”
Type “cd Project3” to enter the extracted folder named Project3 containing the Python code
In order to compare two given sentences:
Type “codeT345.py “sent1” “sent2””, and hit enter. Sent1 is the original sentence you would like to use and sent2 is the candidate sentence used in calculating edit distance score and percent match
The program will then output a possible minimum edit distance alignment, percent match and the edit distance score
In order to print the candidates for T5:
Type “codeT345.py” and hit enter. Note, there should not be any command-line arguments
This will print source sentences and candidates for EDS and PM, similar to what is shown below
The EMEA corpus files must be in the same directory for this option
The output is in the form of:
[source sentence]
[EDS candidate and alignment x10]
[Percent Match candidate x10]
D2. Your random sets from T5 and the top ten candidates for each of your five MTBT sentences using PM and using EDScore.

Menitorix and associated names (See Annex I) powder and solvent for solution for injection Haemophilus type b and Meningococcal group C conjugate vaccine [See Annex I – To be completed nationally]

*******TOP TEN EDS CANDIDATES AND ALIGNMENTS*********

 Menitorix and associated names (See Annex I) powder and solvent for solution for injection Haemophilus type b and Meningococcal group C conjugate vaccine [See Annex I – To be completed 
nationally]
['Menitorix->Menitorix 0.0', 'and->and 0.0', 'associated->associated 0.0', 'names->names 0.0', '(See->(See 0.0', 'Annex->Annex 0.0', 'I)->I) 0.0', 'powder->powder 0.0', 'and->and 0.0', 'solvent->solvent 0.0', 'for->for 0.0', 'solution->solution 0.0', 'for->for 0.0', 'injection->injection 0.0', 'Haemophilus->Haemophilus 0.0', 'type->type 0.0', 'b->b 0.0', 'and->and 0.0', 'Meningococcal->Meningococcal 0.0', 'group->group 0.0', 'C->C 0.0', 'conjugate->conjugate 0.0', 'vaccine->vaccine 0.0', '[See->[See 0.0', 'Annex->Annex 0.0', 'I->I 0.0', '–->– 0.0', 'To->To 0.0', 'be->be 0.0', 'completed->completed 0.0', 'nationally]->nationally] 0.0']

 Lamictal and associated names (see Annex I) 200 mg dispersible/ chewable tablets [See Annex I - To be completed nationally] Lamotrigine
['Menitorix->Lamictal 1.0', 'and->and 0.0', 'associated->associated 0.0', 'names->names 0.0', '(See->(see 1.0', 'Annex->Annex 0.0', 'I)->I) 0.0', 'powder->* 1.0', 'and->* 1.0', 'solvent->* 1.0', 'for->* 1.0', 'solution->* 1.0', 'for->* 1.0', 'injection->* 1.0', 'Haemophilus->* 1.0', 'type->* 1.0', 'b->* 1.0', 'and->* 1.0', 'Meningococcal->200 1.0', 'group->mg 1.0', 'C->dispersible/ 1.0', 'conjugate->chewable 1.0', 'vaccine->tablets 1.0', '[See->[See 0.0', 'Annex->Annex 0.0', 'I->I 0.0', '–->- 1.0', 'To->To 0.0', 'be->be 0.0', 'completed->completed 0.0', 'nationally]->nationally] 0.0', '*->Lamotrigine 1.0']

 [See Annex I - To be completed nationally]
['Menitorix->* 1.0', 'and->* 1.0', 'associated->* 1.0', 'names->* 1.0', '(See->* 1.0', 'Annex->* 1.0', 'I)->* 1.0', 'powder->* 1.0', 'and->nationally] 1.0', 'solvent->nationally] 1.0', 'for->nationally] 1.0', 'solution->nationally] 1.0', 'for->nationally] 2.0', 'injection->nationally] 2.0', 'Haemophilus->nationally] 2.0', 'type->nationally] 2.0', 'b->nationally] 2.0', 'and->nationally] 2.0', 'Meningococcal->nationally] 2.0', 'group->nationally] 2.0', 'C->nationally] 2.0', 'conjugate->nationally] 2.0', 'vaccine->nationally] 2.0', '[See->[See 0.0', 'Annex->Annex 0.0', 'I->I 0.0', '–->- 1.0', 'To->To 0.0', 'be->be 0.0', 'completed->completed 0.0', 'nationally]->nationally] 0.0']

 KOGENATE Bayer 2000 IU powder and solvent for solution for injection Recombinant coagulation factor VIII (octocog alfa)
['Menitorix->* 1.0', 'and->* 1.0', 'associated->* 1.0', 'names->KOGENATE 1.0', '(See->Bayer 1.0', 'Annex->2000 1.0', 'I)->IU 1.0', 'powder->powder 0.0', 'and->and 0.0', 'solvent->solvent 0.0', 'for->for 0.0', 'solution->solution 0.0', 'for->for 0.0', 'injection->injection 0.0', 'Haemophilus->* 1.0', 'type->* 1.0', 'b->* 1.0', 'and->* 1.0', 'Meningococcal->* 1.0', 'group->* 1.0', 'C->* 1.0', 'conjugate->* 1.0', 'vaccine->* 1.0', '[See->* 1.0', 'Annex->* 1.0', 'I->Recombinant 1.0', '–->coagulation 1.0', 'To->factor 1.0', 'be->VIII 1.0', 'completed->(octocog 1.0', 'nationally]->alfa) 1.0']

 Puregon 100 IU powder and solvent for solution for injection follitropin beta
['Menitorix->* 1.0', 'and->* 1.0', 'associated->* 1.0', 'names->* 1.0', '(See->Puregon 1.0', 'Annex->100 1.0', 'I)->IU 1.0', 'powder->powder 0.0', 'and->and 0.0', 'solvent->solvent 0.0', 'for->for 0.0', 'solution->solution 0.0', 'for->for 0.0', 'injection->injection 0.0', 'Haemophilus->* 1.0', 'type->* 1.0', 'b->* 1.0', 'and->* 1.0', 'Meningococcal->* 1.0', 'group->* 1.0', 'C->* 1.0', 'conjugate->* 1.0', 'vaccine->* 1.0', '[See->* 1.0', 'Annex->* 1.0', 'I->* 1.0', '–->* 1.0', 'To->* 1.0', 'be->* 1.0', 'completed->follitropin 1.0', 'nationally]->beta 1.0']

 ReFacto AF 2000 IU powder and solvent for solution for injection Moroctocog alfa
['Menitorix->* 1.0', 'and->* 1.0', 'associated->* 1.0', 'names->ReFacto 1.0', '(See->AF 1.0', 'Annex->2000 1.0', 'I)->IU 1.0', 'powder->powder 0.0', 'and->and 0.0', 'solvent->solvent 0.0', 'for->for 0.0', 'solution->solution 0.0', 'for->for 0.0', 'injection->injection 0.0', 'Haemophilus->* 1.0', 'type->* 1.0', 'b->* 1.0', 'and->* 1.0', 'Meningococcal->* 1.0', 'group->* 
1.0', 'C->* 1.0', 'conjugate->* 1.0', 'vaccine->* 1.0', '[See->* 1.0', 'Annex->* 1.0', 'I->* 1.0', '–->* 1.0', 'To->* 1.0', 'be->* 1.0', 'completed->Moroctocog 1.0', 'nationally]->alfa 1.0']

 - 4 vials of powder for solution for injection and 4 ampoules of solvent for parenteral use;
['Menitorix->* 1.0', 'and->* 1.0', 'associated->* 1.0', 'names->- 1.0', '(See->4 1.0', 'Annex->vials 1.0', 'I)->of 1.0', 'powder->powder 0.0', 'and->* 1.0', 'solvent->* 1.0', 'for->for 0.0', 'solution->solution 0.0', 'for->for 0.0', 'injection->injection 0.0', 'Haemophilus->* 1.0', 'type->* 1.0', 'b->* 1.0', 'and->and 0.0', 'Meningococcal->* 1.0', 'group->* 1.0', 'C->* 
1.0', 'conjugate->* 1.0', 'vaccine->* 1.0', '[See->* 1.0', 'Annex->4 1.0', 'I->ampoules 1.0', '–->of 1.0', 'To->solvent 1.0', 'be->for 1.0', 'completed->parenteral 1.0', 'nationally]->use; 1.0']

 Powder and solvent for solution for injection
['Menitorix->Powder 1.0', 'and->and 0.0', 'associated->* 1.0', 'names->* 1.0', '(See->* 1.0', 'Annex->* 1.0', 'I)->* 1.0', 'powder->* 1.0', 'and->* 1.0', 'solvent->solvent 0.0', 'for->for 0.0', 'solution->solution 0.0', 'for->for 0.0', 'injection->injection 0.0', 'Haemophilus->* 1.0', 'type->* 1.0', 'b->* 1.0', 'and->* 1.0', 'Meningococcal->* 1.0', 'group->* 1.0', 'C->* 1.0', 'conjugate->* 1.0', 'vaccine->* 1.0', '[See->* 1.0', 'Annex->* 1.0', 'I->* 1.0', '–->* 1.0', 'To->* 1.0', 'be->* 1.0', 'completed->* 1.0', 'nationally]->* 1.0']

 [See Annex I - To be completed nationally
['Menitorix->* 1.0', 'and->* 1.0', 'associated->* 1.0', 'names->* 1.0', '(See->* 1.0', 'Annex->* 1.0', 'I)->* 1.0', 'powder->* 1.0', 'and->nationally 1.0', 'solvent->nationally 1.0', 'for->nationally 1.0', 'solution->nationally 1.0', 'for->nationally 2.0', 'injection->nationally 2.0', 'Haemophilus->nationally 2.0', 'type->nationally 2.0', 'b->nationally 2.0', 'and->nationally 2.0', 'Meningococcal->nationally 2.0', 'group->nationally 2.0', 'C->nationally 2.0', 'conjugate->nationally 2.0', 'vaccine->nationally 2.0', '[See->[See 0.0', 'Annex->Annex 0.0', 
'I->I 0.0', '–->- 1.0', 'To->To 0.0', 'be->be 0.0', 'completed->completed 0.0', 'nationally]->nationally 1.0']

 NeoRecormon 10,000 IU Lyophilisate and solvent for solution for injection in cartridge (10,000 IU/ml) Epoetin beta
['Menitorix->* 1.0', 'and->* 1.0', 'associated->* 1.0', 'names->* 1.0', '(See->NeoRecormon 1.0', 'Annex->10,000 1.0', 'I)->IU 1.0', 'powder->Lyophilisate 1.0', 'and->and 0.0', 'solvent->solvent 0.0', 'for->for 0.0', 'solution->solution 0.0', 'for->for 0.0', 'injection->injection 0.0', 'Haemophilus->* 1.0', 'type->* 1.0', 'b->* 1.0', 'and->* 1.0', 'Meningococcal->* 1.0', 'group->* 1.0', 'C->* 1.0', 'conjugate->* 1.0', 'vaccine->* 1.0', '[See->* 1.0', 'Annex->* 1.0', 'I->in 1.0', '–->cartridge 1.0', 'To->(10,000 1.0', 'be->IU/ml) 1.0', 'completed->Epoetin 1.0', 'nationally]->beta 1.0']

**********TOP TEN PERCENT MATCH CANDIDATES***********

 Menitorix and associated names (See Annex I) powder and solvent for solution for injection Haemophilus type b and Meningococcal group C conjugate vaccine [See Annex I – To be completed 
nationally]

 Lamictal and associated names (see Annex I) 200 mg dispersible/ chewable tablets [See Annex I - To be completed nationally] Lamotrigine

 [See Annex I - To be completed nationally]

 Do not confuse ZYPADHERA 300 mg powder and solvent for prolonged release suspension for injection with olanzapine 10 mg powder for solution for injection.

 Puregon 100 IU powder and solvent for solution for injection (powder for injection) is a white to off- white cake or powder and is supplied in a glass ampoule.

 - 4 vials of powder for solution for injection and 4 ampoules of solvent for parenteral use;

 KOGENATE Bayer 2000 IU powder and solvent for solution for injection Recombinant coagulation factor VIII (octocog alfa)

 Puregon 100 IU powder and solvent for solution for injection follitropin beta

 [See Annex I - To be completed nationally

 Simulect powder Colourless type I glass vial, grey fluor-resin coated butyl rubber stopper, held in place by a flanged aluminium band, blue polypropylene flip-off cap, containing 20 mg 
basiliximab as powder for solution for injection or infusion.


122 MINIMUM PARTICULARS TO APPEAR ON SMALL IMMEDIATE PACKAGING UNITS

*******TOP TEN EDS CANDIDATES AND ALIGNMENTS*********

 169 MINIMUM PARTICULARS TO APPEAR ON SMALL IMMEDIATE PACKAGING UNITS
['122->169 1.0', 'MINIMUM->MINIMUM 0.0', 'PARTICULARS->PARTICULARS 0.0', 'TO->TO 0.0', 'APPEAR->APPEAR 0.0', 'ON->ON 0.0', 'SMALL->SMALL 0.0', 'IMMEDIATE->IMMEDIATE 0.0', 'PACKAGING->PACKAGING 0.0', 'UNITS->UNITS 0.0']

 72 MINIMUM PARTICULARS TO APPEAR ON SMALL IMMEDIATE PACKAGING UNITS
['122->72 1.0', 'MINIMUM->MINIMUM 0.0', 'PARTICULARS->PARTICULARS 0.0', 'TO->TO 0.0', 'APPEAR->APPEAR 0.0', 'ON->ON 0.0', 'SMALL->SMALL 0.0', 'IMMEDIATE->IMMEDIATE 0.0', 'PACKAGING->PACKAGING 0.0', 'UNITS->UNITS 0.0']

 320 MINIMUM PARTICULARS TO APPEAR ON SMALL IMMEDIATE PACKAGING UNITS
['122->320 1.0', 'MINIMUM->MINIMUM 0.0', 'PARTICULARS->PARTICULARS 0.0', 'TO->TO 0.0', 'APPEAR->APPEAR 0.0', 'ON->ON 0.0', 'SMALL->SMALL 0.0', 'IMMEDIATE->IMMEDIATE 0.0', 'PACKAGING->PACKAGING 0.0', 'UNITS->UNITS 0.0']

 236 MINIMUM PARTICULARS TO APPEAR ON SMALL IMMEDIATE PACKAGING UNITS
['122->236 1.0', 'MINIMUM->MINIMUM 0.0', 'PARTICULARS->PARTICULARS 0.0', 'TO->TO 0.0', 'APPEAR->APPEAR 0.0', 'ON->ON 0.0', 'SMALL->SMALL 0.0', 'IMMEDIATE->IMMEDIATE 0.0', 'PACKAGING->PACKAGING 0.0', 'UNITS->UNITS 0.0']

 17 MINIMUM PARTICULARS TO APPEAR ON SMALL IMMEDIATE PACKAGING UNITS
['122->17 1.0', 'MINIMUM->MINIMUM 0.0', 'PARTICULARS->PARTICULARS 0.0', 'TO->TO 0.0', 'APPEAR->APPEAR 0.0', 'ON->ON 0.0', 'SMALL->SMALL 0.0', 'IMMEDIATE->IMMEDIATE 0.0', 'PACKAGING->PACKAGING 0.0', 'UNITS->UNITS 0.0']

 191 MINIMUM PARTICULARS TO APPEAR ON SMALL IMMEDIATE PACKAGING UNITS
['122->191 1.0', 'MINIMUM->MINIMUM 0.0', 'PARTICULARS->PARTICULARS 0.0', 'TO->TO 0.0', 'APPEAR->APPEAR 0.0', 'ON->ON 0.0', 'SMALL->SMALL 0.0', 'IMMEDIATE->IMMEDIATE 0.0', 'PACKAGING->PACKAGING 0.0', 'UNITS->UNITS 0.0']

 242 MINIMUM PARTICULARS TO APPEAR ON SMALL IMMEDIATE PACKAGING UNITS
['122->242 1.0', 'MINIMUM->MINIMUM 0.0', 'PARTICULARS->PARTICULARS 0.0', 'TO->TO 0.0', 'APPEAR->APPEAR 0.0', 'ON->ON 0.0', 'SMALL->SMALL 0.0', 'IMMEDIATE->IMMEDIATE 0.0', 'PACKAGING->PACKAGING 0.0', 'UNITS->UNITS 0.0']

 28 MINIMUM PARTICULARS TO APPEAR ON SMALL IMMEDIATE PACKAGING UNITS
['122->28 1.0', 'MINIMUM->MINIMUM 0.0', 'PARTICULARS->PARTICULARS 0.0', 'TO->TO 0.0', 'APPEAR->APPEAR 0.0', 'ON->ON 0.0', 'SMALL->SMALL 0.0', 'IMMEDIATE->IMMEDIATE 0.0', 'PACKAGING->PACKAGING 0.0', 'UNITS->UNITS 0.0']

 20 MINIMUM PARTICULARS TO APPEAR ON SMALL IMMEDIATE PACKAGING UNITS
['122->20 1.0', 'MINIMUM->MINIMUM 0.0', 'PARTICULARS->PARTICULARS 0.0', 'TO->TO 0.0', 'APPEAR->APPEAR 0.0', 'ON->ON 0.0', 'SMALL->SMALL 0.0', 'IMMEDIATE->IMMEDIATE 0.0', 'PACKAGING->PACKAGING 0.0', 'UNITS->UNITS 0.0']

 23/ 37 MINIMUM PARTICULARS TO APPEAR ON SMALL IMMEDIATE PACKAGING UNITS
['*->23/ 1.0', '122->37 1.0', 'MINIMUM->MINIMUM 0.0', 'PARTICULARS->PARTICULARS 0.0', 'TO->TO 0.0', 'APPEAR->APPEAR 0.0', 'ON->ON 0.0', 'SMALL->SMALL 0.0', 'IMMEDIATE->IMMEDIATE 0.0', 'PACKAGING->PACKAGING 0.0', 'UNITS->UNITS 0.0']

**********TOP TEN PERCENT MATCH CANDIDATES***********

 169 MINIMUM PARTICULARS TO APPEAR ON SMALL IMMEDIATE PACKAGING UNITS

 72 MINIMUM PARTICULARS TO APPEAR ON SMALL IMMEDIATE PACKAGING UNITS

 320 MINIMUM PARTICULARS TO APPEAR ON SMALL IMMEDIATE PACKAGING UNITS

 236 MINIMUM PARTICULARS TO APPEAR ON SMALL IMMEDIATE PACKAGING UNITS

 17 MINIMUM PARTICULARS TO APPEAR ON SMALL IMMEDIATE PACKAGING UNITS

 23/ 37 MINIMUM PARTICULARS TO APPEAR ON SMALL IMMEDIATE PACKAGING UNITS

 141 MINIMUM PARTICULARS TO APPEAR ON SMALL IMMEDIATE PACKAGING UNITS GONAL-f 450 IU/ 0.75 ml (33 micrograms/ 0.75 ml), VIAL LABEL

 191 MINIMUM PARTICULARS TO APPEAR ON SMALL IMMEDIATE PACKAGING UNITS

 242 MINIMUM PARTICULARS TO APPEAR ON SMALL IMMEDIATE PACKAGING UNITS

 28 MINIMUM PARTICULARS TO APPEAR ON SMALL IMMEDIATE PACKAGING UNITS


It is recommended that patients who have pre-existing cardiac abnormalities have an electrocardiogram prior to initiation of Pegasys therapy.

*******TOP TEN EDS CANDIDATES AND ALIGNMENTS*********

 It is recommended that those patients who have pre-existing cardiac abnormalities have electrocardiograms taken prior to and during the course of treatment.
['It->It 0.0', 'is->is 0.0', 'recommended->recommended 0.0', 'that->that 0.0', '*->those 1.0', 'patients->patients 0.0', 'who->who 0.0', 'have->have 0.0', 'pre-existing->pre-existing 0.0', 'cardiac->cardiac 0.0', 'abnormalities->abnormalities 0.0', 'have->have 0.0', 'an->electrocardiograms 1.0', 'electrocardiogram->taken 1.0', 'prior->prior 0.0', 'to->to 0.0', '*->and 1.0', '*->during 1.0', 'initiation->the 1.0', 'of->course 1.0', 'Pegasys->of 1.0', 'therapy.->treatment. 1.0']

 It is recommended that the platelet count is regularly monitored during the first 8 weeks of therapy.
['It->It 0.0', 'is->is 0.0', 'recommended->recommended 0.0', 'that->that 0.0', 'patients->* 1.0', 'who->the 1.0', 'have->platelet 1.0', 'pre-existing->count 1.0', 'cardiac->is 1.0', 'abnormalities->regularly 1.0', 'have->monitored 1.0', 'an->during 1.0', 'electrocardiogram->the 1.0', 'prior->first 1.0', 'to->8 1.0', 'initiation->weeks 1.0', 'of->of 0.0', 'Pegasys->* 1.0', 'therapy.->therapy. 0.0']

 It is recommended that SUSTIVA be taken on an empty stomach.
['It->It 0.0', 'is->is 0.0', 'recommended->recommended 0.0', 'that->that 0.0', 'patients->* 1.0', 'who->* 1.0', 'have->* 1.0', 'pre-existing->SUSTIVA 1.0', 'cardiac->be 1.0', 'abnormalities->taken 1.0', 'have->on 1.0', 'an->an 0.0', 'electrocardiogram->* 1.0', 'prior->* 1.0', 'to->* 1.0', 'initiation->* 1.0', 'of->* 1.0', 'Pegasys->empty 1.0', 'therapy.->stomach. 1.0'] 

 It is essential for patients with pre-existing or gestational diabetes to maintain good metabolic control throughout pregnancy.
['It->It 0.0', 'is->is 0.0', 'recommended->essential 1.0', 'that->for 1.0', 'patients->patients 0.0', 'who->* 1.0', 'have->with 1.0', 'pre-existing->pre-existing 0.0', 'cardiac->* 1.0', 
'abnormalities->or 1.0', 'have->gestational 1.0', 'an->diabetes 1.0', 'electrocardiogram->to 1.0', 'prior->maintain 1.0', 'to->good 1.0', 'initiation->metabolic 1.0', 'of->control 1.0', 
'Pegasys->throughout 1.0', 'therapy.->pregnancy. 1.0']

 It is recommended that the date of the first use be noted on the label.
['It->It 0.0', 'is->is 0.0', 'recommended->recommended 0.0', 'that->that 0.0', 'patients->* 1.0', 'who->* 1.0', 'have->* 1.0', 'pre-existing->* 1.0', 'cardiac->the 1.0', 'abnormalities->date 1.0', 'have->of 1.0', 'an->the 1.0', 'electrocardiogram->first 1.0', 'prior->use 1.0', 'to->be 1.0', 'initiation->noted 1.0', 'of->on 1.0', 'Pegasys->the 1.0', 'therapy.->label. 1.0']

 It is recommended that digoxin levels be monitored when digoxin is combined with INTELENCE.
['It->It 0.0', 'is->is 0.0', 'recommended->recommended 0.0', 'that->that 0.0', 'patients->* 1.0', 'who->* 1.0', 'have->* 1.0', 'pre-existing->* 1.0', 'cardiac->* 1.0', 'abnormalities->digoxin 1.0', 'have->levels 1.0', 'an->be 1.0', 'electrocardiogram->monitored 1.0', 'prior->when 1.0', 'to->digoxin 1.0', 'initiation->is 1.0', 'of->combined 1.0', 'Pegasys->with 1.0', 'therapy.->INTELENCE. 1.0']

 It is recommended that gloves are used as ZYPADHERA may irritate the skin.
['It->It 0.0', 'is->is 0.0', 'recommended->recommended 0.0', 'that->that 0.0', 'patients->* 1.0', 'who->* 1.0', 'have->* 1.0', 'pre-existing->* 1.0', 'cardiac->* 1.0', 'abnormalities->* 
1.0', 'have->gloves 1.0', 'an->are 1.0', 'electrocardiogram->used 1.0', 'prior->as 1.0', 'to->ZYPADHERA 1.0', 'initiation->may 1.0', 'of->irritate 1.0', 'Pegasys->the 1.0', 'therapy.->skin. 1.0']

 It is recommended that you measure your blood glucose regularly.
['It->It 0.0', 'is->is 0.0', 'recommended->recommended 0.0', 'that->that 0.0', 'patients->* 1.0', 'who->* 1.0', 'have->* 1.0', 'pre-existing->* 1.0', 'cardiac->* 1.0', 'abnormalities->* 
1.0', 'have->* 1.0', 'an->* 1.0', 'electrocardiogram->* 1.0', 'prior->you 1.0', 'to->measure 1.0', 'initiation->your 1.0', 'of->blood 1.0', 'Pegasys->glucose 1.0', 'therapy.->regularly. 
1.0']

 It is advisable to rehydrate patients prior to starting therapy with etoricoxib.
['It->It 0.0', 'is->is 0.0', 'recommended->* 1.0', 'that->* 1.0', 'patients->* 1.0', 'who->* 1.0', 'have->* 1.0', 'pre-existing->* 1.0', 'cardiac->* 1.0', 'abnormalities->advisable 1.0', 'have->to 1.0', 'an->rehydrate 1.0', 'electrocardiogram->patients 1.0', 'prior->prior 0.0', 'to->to 0.0', 'initiation->starting 1.0', 'of->therapy 1.0', 'Pegasys->with 1.0', 'therapy.->etoricoxib. 1.0']

 It is for use in patients who have stopped responding to, or cannot take, other antiviral medicines.
['It->It 0.0', 'is->is 0.0', '*->for 1.0', 'recommended->use 1.0', 'that->in 1.0', 'patients->patients 0.0', 'who->who 0.0', 'have->have 0.0', 'pre-existing->* 1.0', 'cardiac->* 1.0', 'abnormalities->* 1.0', 'have->stopped 1.0', 'an->responding 1.0', 'electrocardiogram->to, 1.0', 'prior->or 1.0', 'to->cannot 1.0', 'initiation->take, 1.0', 'of->other 1.0', 'Pegasys->antiviral 1.0', 'therapy.->medicines. 1.0']

**********TOP TEN PERCENT MATCH CANDIDATES***********

 It is recommended that those patients who have pre-existing cardiac abnormalities and/or are in advanced stages of cancer have electrocardiograms taken prior to and during the course of treatment.

 It is recommended that those patients who have pre-existing cardiac abnormalities have electrocardiograms taken prior to and during the course of treatment.

 In populations similar to that enrolled in the PREDICT-1 study, it is estimated that 48% to 61% of patients with the HLA-B*5701 allele will develop a hypersensitivity reaction during the course of abacavir treatment compared with 0% to 4% of patients who do not have the HLA-B*5701 allele.

 ge Trudexa 40 mg every other week was assessed in 393 patients in two randomised, 24 week double− blind, placebo− controlled studies in patients with active ankylosing spondylitis (mean lon baseline score of disease activity [Bath Ankylosing Spondylitis Disease Activity Index (BASDAI)] was 6.3 in all groups) who have had an inadequate response to conventional therapy. 

 It is used in patients with: • compensated liver disease (when the liver is damaged but functions normally), who also show signs that the virus is still multiplying, and have signs of liver damage (raised levels of the liver enzyme ‘ alanine aminotransferase’ [ALT] and signs of damage when liver tissue is examined under a microscope); • decompensated liver disease (when the liver is damaged and does not function normally).

 HYCAMTIN is contraindicated in patients who − have a history of hypersensitivity to the active substance or to any of the excipients − are breast feeding (see section 4.6) − already have severe bone marrow depression prior to starting first course, as evidenced by baseline neutrophils < 1.5 x 109/ l and/ or a platelet count of < 100 x 109/ l.

 The Committee for Medicinal products for Human Use (CHMP) decided that SOMAVERT’ S benefits are greater than its risks for the treatment of patients with acromegaly who have had an inadequate response to surgery and/ or radiation therapy and in whom an appropriate medical treatment with somatostatin analogues did not normalise IGF-I concentrations or was not tolerated.

 In patients with an allergy to animal insulin intradermal skin testing is recommended prior to a transfer to Insuman Comb 15, since they may experience immunological cross-reactions.   

 Dual blockade of the renin-angiotensin-aldosterone system (e. g. by adding an ACE- inhibitor to an angiotensin II receptor antagonist) is therefore not recommended in patients with already controlled blood pressure and should be limited to individually defined cases with close monitoring of renal function.

 General medical supportive measures should be administered to patients who receive an overdose until the exaggerated pharmacological effects of the medicinal product have resolved.     


Activated factor X converts prothrombin into thrombin.

*******TOP TEN EDS CANDIDATES AND ALIGNMENTS*********

 X
['Activated->* 1.0', 'factor->X 1.0', 'X->X 0.0', 'converts->* 1.0', 'prothrombin->* 1.0', 'into->* 1.0', 'thrombin.->* 1.0']

 SPECIAL STORAGE PRECAUTIONS
['Activated->* 1.0', 'factor->* 1.0', 'X->* 1.0', 'converts->PRECAUTIONS 1.0', 'prothrombin->SPECIAL 1.0', 'into->STORAGE 1.0', 'thrombin.->PRECAUTIONS 1.0']

 Acute and chronic toxicity: oral acute and chronic toxicity studies were conducted in the mouse (500 mg/kg/day), rat (up to 1,000 mg/kg/day) and monkey (up to 800 mg/kg/day).
['*->Acute 1.0', '*->and 1.0', '*->chronic 1.0', '*->toxicity: 1.0', '*->oral 1.0', '*->acute 1.0', '*->and 1.0', 'thrombin.->chronic 1.0', 'thrombin.->toxicity 1.0', 'thrombin.->studies 1.0', 'thrombin.->were 1.0', 'thrombin.->conducted 1.0', 'thrombin.->in 1.0', 'thrombin.->the 1.0', 'thrombin.->mouse 1.0', 'thrombin.->(500 1.0', 'thrombin.->mg/kg/day), 1.0', 'thrombin.->rat 1.0', 'thrombin.->(up 1.0', 'thrombin.->to 1.0', 'thrombin.->1,000 1.0', 'Activated->mg/kg/day) 1.0', 'factor->and 1.0', 'X->monkey 1.0', 'converts->(up 1.0', 'prothrombin->to 1.0', 'into->800 1.0', 'thrombin.->mg/kg/day). 1.0']

 As per the CHMP Guideline on Risk Management Systems for medicinal products for human use, the updated RMP should be submitted at the same time as the next Periodic Safety Update Report (PSUR).
['*->As 1.0', '*->per 1.0', '*->the 1.0', '*->CHMP 1.0', '*->Guideline 1.0', '*->on 1.0', '*->Risk 1.0', 'thrombin.->Management 1.0', 'thrombin.->Systems 1.0', 'thrombin.->for 1.0', 'thrombin.->medicinal 1.0', 'thrombin.->products 1.0', 'thrombin.->for 1.0', 'thrombin.->human 1.0', 'thrombin.->use, 1.0', 'thrombin.->the 1.0', 'thrombin.->updated 1.0', 'thrombin.->RMP 1.0', 'thrombin.->should 1.0', 'thrombin.->be 1.0', 'thrombin.->submitted 1.0', 'thrombin.->at 1.0', 'thrombin.->the 1.0', 'thrombin.->same 1.0', 'thrombin.->time 1.0', 'thrombin.->as 1.0', 'Activated->the 1.0', 'factor->next 1.0', 'X->Periodic 1.0', 'converts->Safety 1.0', 'prothrombin->Update 1.0', 'into->Report 1.0', 'thrombin.->(PSUR). 1.0']

 Do not freeze.
['Activated->* 1.0', 'factor->* 1.0', 'X->* 1.0', 'converts->freeze. 1.0', 'prothrombin->Do 1.0', 'into->not 1.0', 'thrombin.->freeze. 1.0']

 Although erlotinib exposure was similar in patients with moderately impaired hepatic function (Child-Pugh score 7-9) compared with patients with adequate hepatic function, caution should be used when administering Tarceva to patients with hepatic impairment.
['*->Although 1.0', '*->erlotinib 1.0', '*->exposure 1.0', '*->was 1.0', '*->similar 1.0', '*->in 1.0', '*->patients 1.0', 'thrombin.->with 1.0', 'thrombin.->moderately 1.0', 'thrombin.->impaired 1.0', 'thrombin.->hepatic 1.0', 'thrombin.->function 1.0', 'thrombin.->(Child-Pugh 1.0', 'thrombin.->score 1.0', 'thrombin.->7-9) 1.0', 'thrombin.->compared 1.0', 'thrombin.->with 1.0', 'thrombin.->patients 1.0', 'thrombin.->with 1.0', 'thrombin.->adequate 1.0', 'thrombin.->hepatic 1.0', 'thrombin.->function, 1.0', 'thrombin.->caution 1.0', 'thrombin.->should 
1.0', 'thrombin.->be 1.0', 'thrombin.->used 1.0', 'thrombin.->when 1.0', 'Activated->administering 1.0', 'factor->Tarceva 1.0', 'X->to 1.0', 'converts->patients 1.0', 'prothrombin->with 
1.0', 'into->hepatic 1.0', 'thrombin.->impairment. 1.0']

 To prepare the solution for infusion or injection, add 5 ml water for injections from the accompanying ampoule to the vial containing the Simulect powder, using aseptic technique.      
['*->To 1.0', '*->prepare 1.0', '*->the 1.0', '*->solution 1.0', '*->for 1.0', '*->infusion 1.0', '*->or 1.0', 'thrombin.->injection, 1.0', 'thrombin.->add 1.0', 'thrombin.->5 1.0', 'thrombin.->ml 1.0', 'thrombin.->water 1.0', 'thrombin.->for 1.0', 'thrombin.->injections 1.0', 'thrombin.->from 1.0', 'thrombin.->the 1.0', 'thrombin.->accompanying 1.0', 'thrombin.->ampoule 1.0', 'thrombin.->to 1.0', 'thrombin.->the 1.0', 'thrombin.->vial 1.0', 'Activated->containing 1.0', 'factor->the 1.0', 'X->Simulect 1.0', 'converts->powder, 1.0', 'prothrombin->using 
1.0', 'into->aseptic 1.0', 'thrombin.->technique. 1.0']

 er Once hypertension is controlled with more intensified therapy, Dynepo therapy should be re-started at a reduced dose. ng Iron evaluation lo
['*->er 1.0', '*->Once 1.0', '*->hypertension 1.0', '*->is 1.0', '*->controlled 1.0', '*->with 1.0', '*->more 1.0', 'thrombin.->intensified 1.0', 'thrombin.->therapy, 1.0', 'thrombin.->Dynepo 1.0', 'thrombin.->therapy 1.0', 'thrombin.->should 1.0', 'thrombin.->be 1.0', 'thrombin.->re-started 1.0', 'thrombin.->at 1.0', 'Activated->a 1.0', 'factor->reduced 1.0', 'X->dose. 1.0', 'converts->ng 1.0', 'prothrombin->Iron 1.0', 'into->evaluation 1.0', 'thrombin.->lo 1.0']

 Rheumatoid arthritis is a long term inflammatory disease of the joints.
['*->Rheumatoid 1.0', '*->arthritis 1.0', '*->is 1.0', '*->a 1.0', 'Activated->long 1.0', 'factor->term 1.0', 'X->inflammatory 1.0', 'converts->disease 1.0', 'prothrombin->of 1.0', 'into->the 1.0', 'thrombin.->joints. 1.0']

 peginterferon alpha/ribavirin
['Activated->* 1.0', 'factor->* 1.0', 'X->alpha/ribavirin 1.0', 'converts->alpha/ribavirin 1.0', 'prothrombin->alpha/ribavirin 1.0', 'into->peginterferon 1.0', 'thrombin.->alpha/ribavirin 1.0']

**********TOP TEN PERCENT MATCH CANDIDATES***********

 As primary growth factor for erythroid development, the natural hormone erythropoietin is produced in the kidney and released into the bloodstream in response to hypoxia.

 Purevax RCP FeLV is a lyophilisate (freeze-dried pellet) and solvent that are made up into a suspension for injection.

 Therapy with Tandemact should not be initiated in patients with increased baseline liver enzyme levels (ALT > 2.5 X upper limit of normal) or with any other evidence of liver disease.  

 Ventavis nebuliser solution should not come into contact with skin and eyes; oral ingestion of Ventavis solution should be avoided.

 11 82 amount of factor VIII inhibitors that you may have and the factor VIII level required.

 Push the plunger all the way into the syringe (see Diagram 10).

 IDflu is given as one ‘ intradermal’ injection into the upper layer of the skin, using a special micro-injection system.

 (44-20) 74 18 84 00 Fax (44-20) 74 18 84 16 E-mail: mail@emea. europa. eu. http: / /www. emea. europa. eu ©EMEA 2007 Reproduction and/ or distribution of this document is authorised for non commercial purposes only provided the EMEA is acknowledged NexGen given as an intravenous injection has been studied in 66 patients who had been previously treated with recombinant 
coagulation factor VIII and 61 children who had not.

 The physician must therefore take possible interactions into account and should always ask his patients about any medicinal products they take.

 - enhances the uptake of potassium into cells.


Any air bubbles will collect at the top of the cartridge • Keeping the needle upwards, turn the cartridge for one click in the direction of the arrow (picture C) • Still with the needle 
upwards, press the push-button fully down (picture D) • A drop of insulin must appear at the needle tip.

*******TOP TEN EDS CANDIDATES AND ALIGNMENTS*********

 However, the CHMP considered that there were concerns regarding the long-term antibody persistence, the adequacy of the safety data set in the light of the CHMP Guideline on Clinical Evaluation of New Vaccines, and the indication of Menitorix for both priming and boosting.
['Any->However, 1.0', 'air->the 1.0', 'bubbles->CHMP 1.0', 'will->considered 1.0', 'collect->that 1.0', 'at->there 1.0', 'the->were 1.0', 'top->concerns 1.0', 'of->regarding 1.0', 'the->the 0.0', 'cartridge->long-term 1.0', '•->antibody 1.0', 'Keeping->persistence, 1.0', 'the->the 0.0', 'needle->* 1.0', 'upwards,->adequacy 1.0', 'turn->of 1.0', 'the->the 0.0', 'cartridge->* 1.0', 'for->safety 1.0', 'one->data 1.0', 'click->set 1.0', 'in->in 0.0', 'the->the 0.0', 'direction->light 1.0', 'of->of 0.0', 'the->the 0.0', 'arrow->* 1.0', '(picture->CHMP 1.0', 'C)->Guideline 1.0', '•->on 1.0', 'Still->Clinical 1.0', 'with->Evaluation 1.0', 'the->of 1.0', 'needle->New 1.0', 'upwards,->Vaccines, 1.0', 'press->and 1.0', 'the->the 0.0', 'push-button->* 1.0', 'fully->* 1.0', 'down->* 1.0', '(picture->* 1.0', 'D)->* 1.0', '•->* 1.0', 'A->* 1.0', 'drop->indication 1.0', 'of->of 0.0', 'insulin->* 1.0', 'must->Menitorix 1.0', 'appear->for 1.0', 'at->both 1.0', 'the->priming 1.0', 'needle->and 1.0', 'tip.->boosting. 1.0']

 The Board also looked at the role of the EMEA in supporting the international relations of the EU, the identification and management of regulatory costs, and also at the role of information technology and quality standards in modern regulatory management.
['Any->* 1.0', 'air->The 1.0', 'bubbles->Board 1.0', 'will->also 1.0', 'collect->looked 1.0', 'at->at 0.0', 'the->the 0.0', 'top->role 1.0', 'of->of 0.0', 'the->the 0.0', 'cartridge->EMEA 1.0', '•->in 1.0', 'Keeping->supporting 1.0', 'the->the 0.0', 'needle->international 1.0', 'upwards,->relations 1.0', 'turn->of 1.0', 'the->the 0.0', 'cartridge->* 1.0', 'for->* 1.0', 
'one->* 1.0', 'click->* 1.0', 'in->EU, 1.0', 'the->the 0.0', 'direction->identification 1.0', 'of->and 1.0', 'the->management 1.0', 'arrow->of 1.0', '(picture->regulatory 1.0', 'C)->costs, 1.0', '•->and 1.0', 'Still->also 1.0', 'with->at 1.0', 'the->the 0.0', 'needle->* 1.0', 'upwards,->* 1.0', 'press->* 1.0', 'the->* 1.0', 'push-button->* 1.0', 'fully->* 1.0', 'down->* 1.0', '(picture->* 1.0', 'D)->* 1.0', '•->role 1.0', 'A->of 1.0', 'drop->information 1.0', 'of->technology 1.0', 'insulin->and 1.0', 'must->quality 1.0', 'appear->standards 1.0', 'at->in 1.0', 'the->modern 1.0', 'needle->regulatory 1.0', 'tip.->management. 1.0']

 Please put the day of first use of the cartridge on the dosing record table as shown in the Instruction Manual of the Puregon Pen.
['Any->* 1.0', 'air->Please 1.0', 'bubbles->put 1.0', 'will->the 1.0', 'collect->day 1.0', 'at->of 1.0', 'the->first 1.0', 'top->use 1.0', 'of->of 0.0', 'the->the 0.0', 'cartridge->cartridge 0.0', '•->* 1.0', 'Keeping->on 1.0', 'the->the 0.0', 'needle->* 1.0', 'upwards,->* 1.0', 'turn->* 1.0', 'the->dosing 1.0', 'cartridge->record 1.0', 'for->table 1.0', 'one->as 1.0', 
'click->shown 1.0', 'in->in 0.0', 'the->the 0.0', 'direction->* 1.0', 'of->* 1.0', 'the->* 1.0', 'arrow->* 1.0', '(picture->* 1.0', 'C)->* 1.0', '•->* 1.0', 'Still->* 1.0', 'with->* 1.0', 'the->* 1.0', 'needle->* 1.0', 'upwards,->* 1.0', 'press->* 1.0', 'the->* 1.0', 'push-button->* 1.0', 'fully->* 1.0', 'down->* 1.0', '(picture->* 1.0', 'D)->* 1.0', '•->* 1.0', 'A->Instruction 1.0', 'drop->Manual 1.0', 'of->of 0.0', 'insulin->* 1.0', 'must->* 1.0', 'appear->* 1.0', 'at->* 1.0', 'the->the 0.0', 'needle->Puregon 1.0', 'tip.->Pen. 1.0']

 Patients appear to be at highest risk for these reactions early in the course of therapy with the onset of the reaction occurring in the majority of cases within the first month of treatment.
['Any->* 1.0', 'air->Patients 1.0', 'bubbles->appear 1.0', 'will->to 1.0', 'collect->be 1.0', 'at->at 0.0', 'the->* 1.0', 'top->* 1.0', 'of->* 1.0', 'the->* 1.0', 'cartridge->* 1.0', '•->* 1.0', 'Keeping->* 1.0', 'the->* 1.0', 'needle->* 1.0', 'upwards,->* 1.0', 'turn->highest 1.0', 'the->risk 1.0', 'cartridge->for 1.0', 'for->these 1.0', 'one->reactions 1.0', 'click->early 1.0', 'in->in 0.0', 'the->the 0.0', 'direction->course 1.0', 'of->of 0.0', 'the->* 1.0', 'arrow->* 1.0', '(picture->* 1.0', 'C)->* 1.0', '•->* 1.0', 'Still->therapy 1.0', 'with->with 0.0', 'the->the 0.0', 'needle->* 1.0', 'upwards,->onset 1.0', 'press->of 1.0', 'the->the 0.0', 'push-button->* 1.0', 'fully->* 1.0', 'down->* 1.0', '(picture->reaction 1.0', 'D)->occurring 1.0', '•->in 1.0', 'A->the 1.0', 'drop->majority 1.0', 'of->of 0.0', 'insulin->cases 1.0', 'must->within 1.0', 'appear->the 1.0', 'at->first 1.0', 'the->month 1.0', 'needle->of 1.0', 'tip.->treatment. 1.0']

 If no insulin appears at the needle tip, step 3 should be repeated two more times until insulin appears at the needle tip.
['Any->* 1.0', 'air->If 1.0', 'bubbles->no 1.0', 'will->insulin 1.0', 'collect->appears 1.0', 'at->at 0.0', 'the->the 0.0', 'top->* 1.0', 'of->* 1.0', 'the->* 1.0', 'cartridge->* 1.0', '•->* 1.0', 'Keeping->* 1.0', 'the->* 1.0', 'needle->needle 0.0', 'upwards,->* 1.0', 'turn->* 1.0', 'the->* 1.0', 'cartridge->* 1.0', 'for->* 1.0', 'one->* 1.0', 'click->* 1.0', 'in->* 1.0', 'the->* 1.0', 'direction->* 1.0', 'of->* 1.0', 'the->* 1.0', 'arrow->* 1.0', '(picture->* 1.0', 'C)->* 1.0', '•->* 1.0', 'Still->* 1.0', 'with->* 1.0', 'the->* 1.0', 'needle->* 1.0', 'upwards,->* 1.0', 'press->* 1.0', 'the->tip, 1.0', 'push-button->step 1.0', 'fully->3 1.0', 'down->should 1.0', '(picture->be 1.0', 'D)->repeated 1.0', '•->two 1.0', 'A->more 1.0', 'drop->times 1.0', 'of->until 1.0', 'insulin->insulin 0.0', 'must->* 1.0', 'appear->appears 1.0', 'at->at 0.0', 'the->the 0.0', 'needle->needle 0.0', 'tip.->tip. 0.0']

 In the light of the above the CHMP concludes that the indication for atorvastatin “ Prevention of cardiovascular events in patients estimated to have a high risk for a first cardiovascular event, as an adjunct to correction of other risk factors .” adequately reflects the available data.
['Any->* 1.0', 'air->* 1.0', 'bubbles->* 1.0', 'will->* 1.0', 'collect->* 1.0', 'at->In 1.0', 'the->the 0.0', 'top->light 1.0', 'of->of 0.0', 'the->the 0.0', 'cartridge->* 1.0', '•->* 1.0', 'Keeping->above 1.0', 'the->the 0.0', 'needle->CHMP 1.0', 'upwards,->concludes 1.0', 'turn->that 1.0', 'the->the 0.0', 'cartridge->indication 1.0', 'for->for 0.0', 'one->atorvastatin 1.0', 'click->“ 1.0', 'in->Prevention 1.0', 'the->of 1.0', 'direction->cardiovascular 1.0', 'of->events 1.0', 'the->in 1.0', 'arrow->patients 1.0', '(picture->estimated 1.0', 'C)->to 1.0', '•->have 1.0', 'Still->a 1.0', 'with->high 1.0', 'the->risk 1.0', 'needle->for 1.0', 'upwards,->a 1.0', 'press->first 1.0', 'the->cardiovascular 1.0', 'push-button->event, 1.0', 'fully->as 1.0', 'down->an 1.0', '(picture->adjunct 1.0', 'D)->to 1.0', '•->correction 1.0', 'A->of 1.0', 'drop->other 1.0', 'of->risk 1.0', 'insulin->factors 1.0', 'must->.” 1.0', 'appear->adequately 1.0', 'at->reflects 1.0', 'the->the 0.0', 'needle->available 1.0', 'tip.->data. 1.0']

 On 13 September 2006 the CVMP considered the detailed grounds for the re-examination of the opinion and confirmed its previous opinion concluding that the marketing authorisations for Suramox 15% LA should be suspended.
['Any->* 1.0', 'air->* 1.0', 'bubbles->On 1.0', 'will->13 1.0', 'collect->September 1.0', 'at->2006 1.0', 'the->the 0.0', 'top->CVMP 1.0', 'of->considered 1.0', 'the->the 0.0', 'cartridge->* 1.0', '•->* 1.0', 'Keeping->* 1.0', 'the->* 1.0', 'needle->* 1.0', 'upwards,->* 1.0', 'turn->* 1.0', 'the->detailed 1.0', 'cartridge->grounds 1.0', 'for->for 0.0', 'one->* 1.0', 'click->* 1.0', 'in->* 1.0', 'the->the 0.0', 'direction->re-examination 1.0', 'of->of 0.0', 'the->the 0.0', 'arrow->* 1.0', '(picture->* 1.0', 'C)->opinion 1.0', '•->and 1.0', 'Still->confirmed 1.0', 'with->its 1.0', 'the->previous 1.0', 'needle->opinion 1.0', 'upwards,->concluding 1.0', 'press->that 1.0', 'the->the 0.0', 'push-button->* 1.0', 'fully->* 1.0', 'down->* 1.0', '(picture->* 1.0', 'D)->* 1.0', '•->* 1.0', 'A->* 1.0', 'drop->marketing 1.0', 'of->authorisations 1.0', 'insulin->for 1.0', 'must->Suramox 1.0', 'appear->15% 1.0', 'at->LA 1.0', 'the->should 1.0', 'needle->be 1.0', 'tip.->suspended. 1.0']

 - the scope of the referral was the harmonisation of the Summaries of Products Characteristics,
['Any->* 1.0', 'air->* 1.0', 'bubbles->* 1.0', 'will->* 1.0', 'collect->* 1.0', 'at->- 1.0', 'the->the 0.0', 'top->scope 1.0', 'of->of 0.0', 'the->the 0.0', 'cartridge->* 1.0', '•->referral 1.0', 'Keeping->was 1.0', 'the->the 0.0', 'needle->* 1.0', 'upwards,->* 1.0', 'turn->* 1.0', 'the->* 1.0', 'cartridge->* 1.0', 'for->* 1.0', 'one->* 1.0', 'click->* 1.0', 'in->* 1.0', 'the->* 1.0', 'direction->harmonisation 1.0', 'of->of 0.0', 'the->the 0.0', 'arrow->* 1.0', '(picture->* 1.0', 'C)->* 1.0', '•->* 1.0', 'Still->* 1.0', 'with->* 1.0', 'the->* 1.0', 'needle->* 1.0', 'upwards,->* 1.0', 'press->* 1.0', 'the->* 1.0', 'push-button->* 1.0', 'fully->* 1.0', 'down->* 1.0', '(picture->* 1.0', 'D)->* 1.0', '•->* 1.0', 'A->* 1.0', 'drop->Summaries 1.0', 'of->of 0.0', 'insulin->* 1.0', 'must->* 1.0', 'appear->* 1.0', 'at->* 1.0', 'the->* 1.0', 'needle->Products 1.0', 'tip.->Characteristics, 1.0']

 Tilt the vial slightly and keep the needle in the lowest part of the vial.
['Any->* 1.0', 'air->* 1.0', 'bubbles->* 1.0', 'will->* 1.0', 'collect->* 1.0', 'at->Tilt 1.0', 'the->the 0.0', 'top->* 1.0', 'of->* 1.0', 'the->vial 1.0', 'cartridge->slightly 1.0', '•->and 1.0', 'Keeping->keep 1.0', 'the->the 0.0', 'needle->needle 0.0', 'upwards,->* 1.0', 'turn->* 1.0', 'the->* 1.0', 'cartridge->* 1.0', 'for->* 1.0', 'one->* 1.0', 'click->* 1.0', 'in->in 0.0', 'the->the 0.0', 'direction->* 1.0', 'of->* 1.0', 'the->* 1.0', 'arrow->* 1.0', '(picture->* 1.0', 'C)->* 1.0', '•->* 1.0', 'Still->* 1.0', 'with->* 1.0', 'the->* 1.0', 'needle->* 1.0', 'upwards,->* 1.0', 'press->* 1.0', 'the->* 1.0', 'push-button->* 1.0', 'fully->* 1.0', 'down->* 1.0', '(picture->* 1.0', 'D)->* 1.0', '•->* 1.0', 'A->lowest 1.0', 'drop->part 1.0', 'of->of 0.0', 'insulin->* 1.0', 'must->* 1.0', 'appear->* 1.0', 'at->* 1.0', 'the->the 0.0', 'needle->* 1.0', 'tip.->vial. 1.0']

 International Units are determined by comparison of the activity of the recombinant interferon alfa-2b with the activity of the international reference preparation of human leukocyte interferon established by the World Health Organisation.
['Any->* 1.0', 'air->* 1.0', 'bubbles->International 1.0', 'will->Units 1.0', 'collect->are 1.0', 'at->determined 1.0', 'the->by 1.0', 'top->comparison 1.0', 'of->of 0.0', 'the->the 0.0', 'cartridge->* 1.0', '•->* 1.0', 'Keeping->* 1.0', 'the->* 1.0', 'needle->* 1.0', 'upwards,->* 1.0', 'turn->* 1.0', 'the->* 1.0', 'cartridge->* 1.0', 'for->* 1.0', 'one->* 1.0', 'click->* 1.0', 'in->* 1.0', 'the->* 1.0', 'direction->activity 1.0', 'of->of 0.0', 'the->the 0.0', 'arrow->* 1.0', '(picture->* 1.0', 'C)->recombinant 1.0', '•->interferon 1.0', 'Still->alfa-2b 1.0', 'with->with 0.0', 'the->the 0.0', 'needle->* 1.0', 'upwards,->activity 1.0', 'press->of 1.0', 'the->the 0.0', 'push-button->* 1.0', 'fully->* 1.0', 'down->* 1.0', '(picture->international 1.0', 'D)->reference 1.0', '•->preparation 1.0', 'A->of 1.0', 'drop->human 1.0', 'of->leukocyte 1.0', 'insulin->interferon 1.0', 'must->established 1.0', 'appear->by 1.0', 'at->the 1.0', 'the->World 1.0', 'needle->Health 1.0', 'tip.->Organisation. 1.0']

**********TOP TEN PERCENT MATCH CANDIDATES***********

 Before use of NovoRapid in the pump system you must have received a comprehensive instruction in the use and information about any actions to be taken in case of illness, too high or too low blood sugar or failure of the pump system. • Before inserting the needle, use soap and water to clean your hands and the skin where the needle is inserted so as to avoid any infection at the infusion site • When you fill a new reservoir, be certain not to leave large air bubbles in either the syringe or the tubing • Changing of the infusion set (tubing and needle) must be done according to the instructions in the product information supplied with the infusion set.

 • Programme of sampling and testing of centrally authorised directive in 2004. products will continue in 2003 Trends: • A new agreement with the European Directorate for the

 It could infect the drops • Gently press on the base of the bottle to release one drop of AZOPT at a time. • Don’ t squeeze the bottle: it is designed so that a gentle press on the bottom is all that it needs (picture 2) • After using AZOPT, press a finger to the corner of your eye, by the nose (picture 3).

 Only use needles that are compatible for use with OptiSet. • Always perform the safety test before each injection. • If you are using a new OptiSet the initial safety test must be done 
with the 8 units preset by the manufacturer. • The dosage selector can only be turned in one direction. • Never turn the dosage selector (i. e. never change the dose) after injection button has been pulled out. • This pen is only for your use.

 Patients appear to be at highest risk for these reactions early in the course of therapy with the onset of the reaction occurring in the majority of cases within the first month of treatment.

 Before removing the needle from the vial, check the syringe for air bubbles that reduce the amount of Liprolog in it.

 The uncommon side-effects (reported in at least 1 in 1000 patients) are: • Increased blood pressure, increased weight, increased lactate in the blood, decreased kidney function, increased blood sugar, increased phosphorus in the blood, decreased potassium in the blood • Nerve disorder, decreased or lack of reflexes, involuntary movements, pain along a nerve, loss of feeling, fainting, dizziness when standing up, painful numbness or tingling, shaking • Irritated eyes, painful eyes, red eyes, itchy eyes, blurred or double vision, reduced vision, or seeing flashing lights • Ear pain, ringing in your ears • Coughing with phlegm, shortness of breath when walking or climbing stairs, stuffy nose, runny nose, or dry nose, decreased breath sounds, water on the lung, loss of voice, difficulty breathing • Difficulty swallowing, gas, dry mouth, loose stools, heartburn, stomach cramps, painful or sore mouth and gums, rectal bleeding • Painful urination, frequent urination, blood in the urine, inability to hold your urine • Fingernail pain; fingernail discomfort, loss of fingernails, hives, skin pain, red skin from sunlight, skin discoloration, red rash, itchy rash, increased sweating, night sweats, white areas on the skin, less hair, overall itching, sores, swollen face • Chest pain, neck pain, groin pain, muscle cramps, pain or weakness, back pain, pain in the arm or leg • Decreased phosphorus in the blood, fluid retention, low albumin in the blood, increased thirst, decreased calcium in the blood, decreased sugar in the blood, decreased sodium in the blood • Thrush, pain and swelling in the nose and throat, skin infections, infection in the lungs, infection due to catheter line, infection, redness or swelling at the site where the needle entered the body • Bruising • Pain at site of tumour, death of the tumour • Decreased blood pressure, 
decreased blood pressure when standing up, coldness in your hands and feet • Chest pain or heaviness, difficulty walking, swelling • Allergic reaction • Decreased liver function, increased size of liver • Pain in the breast • Restlessness

 The Committee for Medicinal Products for Human Use (CHMP) decided that, in combination with dexamethasone, Revlimid’ s benefits are greater than its risks for the treatment of multiple 
myeloma patients who have received at least one prior therapy.

 Based on the results of interaction studies conducted with vardenafil in patients with benign prostatic hyperplasia (BPH) on stable tamsulosin or terazosin therapy: • When vardenafil was given at doses of 5, 10 or 20 mg on a background of stable therapy with tamsulosin, there was no symptomatic reduction in blood pressure, although 3/ 21 tamsulosin treated subjects exhibited transient standing systolic blood pressures of less than 85 mmHg. • When vardenafil 5 mg was given simultaneously with terazosin 5 or 10 mg, one of 21 patients experienced symptomatic postural hypotension.

 • If no insulin comes out, check for air bubbles and repeat the safety test two more times to remove them. • If still no insulin comes out, the needle may be blocked.


D3: Write up your analysis of the results of the TM Retrieval experiments from T5/T6. 
	Some of the interesting features from the results of the TM Retrieval experiments was the prevalence of deletions. Deletion was by far the most commonly used operation. All of the operations, besides an equal substitution, had a cost of 1.0 so it was interesting to see the occasional use of an equal substitution. A medical record was used so it isn’t as surprising, but the use of acronyms and scientific names was rather common in the results. Normally, those would be uncommon. There was one result that attempted to include an email and website, while not done correctly, it was interesting to see it try, and it was close as the attempt could be recognized. Although some of the translation candidates were not similar to the original sentence, this is to be expected due to us using only part of the corpus as our TMB, which would limit the possible candidates.

D4. Responses to the following questions:
What was easy about this assignment?
	The implementation of the edit distance algorithm using the dynamic programming algorithm discussed in class was an easier portion of the assignment because of the various decisions held. This meant that it wasn't breaking new ground but reinforcing the knowledge. The switch from using edit distance for words to using edit distance score for sentences was also fairly easy, as it involved a few small changes to the original algorithm.

What was challenging about this assignment?
	Generating the top ten translation candidates from the EMEA corpus was somewhat challenging due to needing to figure out how to use the current algorithms and the corpus together to get the candidates. 

What did you like about this assignment?
	What we enjoyed about this assignment was the skills learned through the implementation of the algorithms. Edit distance, translation memory retrieval, and percent match are all useful concepts to have an understanding of. While our implementations of those concepts may be on the more basic level, they serve as a solid foundation for later improvement. It is these valuable lessons learned that we enjoyed as they will provide benefit later in life.

What did you dislike about this assignment?
	I don’t think we had any issues with this assignment in terms of its usefulness. I think it was very worthwhile, especially given the current world situation. 

What did you learn from this assignment? 
	We learned more about the specifics and implementation of the edit distance and percent match algorithms and were able to learn about what a real world application would look like.

