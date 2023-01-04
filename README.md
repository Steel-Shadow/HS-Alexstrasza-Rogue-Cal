# HS_SPR_CAL
Hearthstone Spectral Pillager Rogue Calculator
炉石鬼灵贼计算器 持续更新中

**写在最前面**：官方插件可以记牌，可以计算场攻，可以算酒馆战棋对战胜率。HDT插件还可以在酒馆战棋决赛时计算不同站位的胜率（假设对手阵容不变）。这个计算器可以计算鬼灵贼的斩杀方式。这些都是计算，没有区别。

</br>
</br>
</br>

**如何使用**

在Windows下使用cmake生成HSSPRCAL.exe。

已生成的HSSPRCAL.exe以及fml.txt在文件夹buildw/下，放在一起使用。

不对该HSSPRCAL.exe负责，如不信任请自行生成。

**How to use**

Use 'cmake' in Windows to generate 'HSSPRCAL.exe'.

A ready 'HSSPRCAL.exe' with 'fml.txt' is in folder 'buildw/'. Put them together to use.

No duty for this 'HSSPRCAL.exe', generate by self if not trust.

</br>
</br>
</br>

**update[20230104]**

1. 现在可以支持殒命暗影（殒命/Demi）（并且已经修复了毒刀不触发殒命暗影的bug），界面中有一个小方框表示“殒命暗影当前复制的法术”，也可以手动调整。

注意现在只支持当殒命暗影复制的有名字的法术时使用它，如果殒命暗影复制的法术是“法术”或者“连法”，暂时不能使用它（主要是因为无法直接确定费用）。之后会具体化每个法术以更多地支持殒命暗影。

注意现在会直接忽视殒命暗影受到的增益或减益效果，始终默认其基础费用为它复制的法术的费用。这可能会犯错，尤其当殒命暗影复制法术之后被黑刀交易减费。之后会修复。

（注意殒命暗影的存在会导致原有的优化逻辑不正确。权衡效率和正确性之后，选择了一个折中的优化逻辑，在一些特殊情况下仍然会犯错。这一点在代码注释中有说明，之后会看情况修改。）

2. 现在可以点击><缩小窗口，点击<>放大窗口，快捷键为-(key:189)。

（2.5. 创造并修复了手牌中随从的血量不会被自动设置，从而导致手动设置的鲨鱼之灵可能被判断为0血的bug）

3. 现在抽随从而爆牌时，会认为从来没有稳定抽到过任何随从。

4. 现在认为行骗会将一张垃圾加入手中。

5. 现在可以支持被沉默的鲨鱼之灵（沉鱼/Shxk），且只能被手动设置在战场上。

6. 现在可以支持奥秘去重，逻辑为只保留最低费的那张（如果已经挂上，则都不保留）。据说没测试过，很可能出错。

7. 根据上次更新提到的：现在可以支持佐拉，且现在裂心者必须手动设置。

</br>
</br>
</br>

**update[20221017]**

1. 现在可能可以支持有关低血破冰的计算，且**总是需要手动将破冰需求设置为1**。如果能破冰，则会给出一个尽可能的低血破冰，其中x血破冰显示为(-x)。目前这一支持的效率可能很低。

2. 现在可能可以支持有关英雄攻击的计算，考虑了原先装备的武器，以及使用黑水弯刀（武器/AnyW）或者疯狂之灾祸（毒刀/Plag）后装备的武器。低血破冰和英雄攻击一定程度上兼容。如果无需低血破冰，英雄攻击将会具有逻辑“英雄攻击后不会再进行任何操作”。如果读取时英雄已经攻击，或者英雄被冰冻，或者敌方有嘲讽随从，都会认为英雄无法进行攻击（以将英雄攻击设置为-1的方式）。因此还无法考虑到使用背刺去除嘲讽等情形。目前这一支持可能使其在某些情况下的效率比原先更低。

3. 可能修复了一些情况下无法正确考虑抽牌效果的BUG。

4. 可能修复了在初始携带的随从被变形的情况下，被认为在牌库的BUG。

5. 增加了适应按钮，有可能可以在炉石程序开启的情况下自动获取路径。增加了回退按钮，在读取之后可能可以使用回退来回到实际早一些的局面。

已知且可能会即将改进的问题：

无法区分被沉默的鲨鱼之灵。

有关中文编码的问题，包括无法正确根据路径读取，以及无法正确显示文字。

算法优化，包括但不仅限于之前各项额外支持反而带来的计算负担。

</br>
</br>
</br>

**update[20221002]**

1. 现在可以在进入时选择英文版。大部分英文缩写取自twitter:nops_hs分享的mega.nz上的可下载英文版，其余英文缩写为作者捏造。

2. 现在能够识别锯齿骨刺、冰霜撕咬的光环buff，冰霜陷阱、触手恐吓者、野蛮的女巫、盘牙蟠蟒的手牌buff。

3. 现在不会将被公爵换走的随从判定在牌库中。

4. 现在不会将行骗(Swin)当作连击法术，并且能够支持行骗（连击时）的抽取随从效果。

5. 现在不会将要挟(SI7.)当作背刺（也因此不会被与背刺有关的优化公式影响）。

6. 现在不会在读取（或读算）时改变时限。

7. 现在修改手牌时会自动附加默认费用。

8. 现在会试图对敌方随从使用可触发特效的骨刺。注意对敌方随从使用背刺和骨刺的逻辑仍是只要最开始能使用或触发特效，就会认为始终能使用或触发特效，所以仍然可能试图对同一个随从连续背刺两次。

9. 现在骨刺友方随从的行为被加入至优化公式中。这可能不那么重要，也可能不那么稳定，你可以酌情考虑更新fml.txt。

10. 出于种种原因，现在能够支持暗影施法者(Cast)、铜须(Bran)、裂心者(Iuca)（其中裂心者会认为对手手牌与自己初始手牌相同，亦即往往只能用于那些刚打出裂心者的情形）。前一者用于某些非主流构筑，后二者用于宇宙牧，并且后二者不会被自动读取，需要手动修改。

补充：宇宙牧可能还会用到佐拉，之后会支持。在更少见的情况下，鬼灵贼可能还会借助被公爵换来的铜须或佐拉完成斩杀，之后这二者会被自动读取。鬼灵贼不太可能借助被公爵换来的裂心者完成斩杀，或者至少逻辑与宇宙牧借助裂心者完成斩杀完全不同，为了防止误导，之后不会被自动读取。之后也有可能支持手动设置对手手牌。

</br>
</br>
</br>

**update[20220923]**

1. 现在会认为被反射工程师变为0血的鲨鱼之灵会在被使用后立即死亡。

2. 现在应该能够正确完整的读入光环buff了。

3. 现在路径中有空格时能够正确保存路径至下次运行。

**以下为新特性**

4. 由于骨刺的存在，“刀一层数”和“刀二层数”被重做为了“下一减费”和“下二减费”，这一重做现在已经体现在界面上了。

5. 读取的快捷键不再是ctrl而是空格，这是为了防止试图截屏时不慎触发读取。

6. 现在增加了读算（读取并计算）按钮，快捷键为=(key:187)。

7. 轻微优化了内存占用，现在应该不那么容易卡死了。

8. 现在界面中清除场上随从时，能够正常同时清除其血量了。

9. **牌库特性** 现在能够读取牌库中的随从（在UI的中间），并且支持帷幕和精灵咏唱者的**确定性**抽取随从效果。

（确定性）抽取随从逻辑为，当抽取随从总量到不小于随从总数时，将所有随从置入手牌，但造成超出手牌上限的部分随从不置入。

注意点1：其实“超出手牌上限的部分随从不置入”逻辑是有问题的，正确的应当为“只要有超出手牌上限的随从则任何随从都不置入”。

注意点2：如果牌库中有两张A随从和一张B随从，逻辑上如果打出帷幕，手中一定会有一张A随从，但是目前不这么认为。

注意点3：如果牌库中有不认识的随从或者认识但并非来自初始套牌的随从，将无法读取到其存在。

注意点4：不支持行骗。

以上几点在之后的更新中会被改进。

**当前版本已知特性，且接下来会改进：**

要挟应当不同于背刺。

应当能够识别冰霜撕咬的光环buff。

应当能够识别触手恐吓者，野蛮的女巫的手牌buff。

**当前版本其他已知特性**：

不和己方英雄攻击力互动。

不和冰箱互动。

存在汉字编码兼容性差的问题。

</br>
</br>
</br>

**update[20220921]**

1. 修复了将黑刀识别为法术，从而可以被伺机待发减费的BUG。现在黑刀将视为新牌名“武器”。

2. 修复了将垂钓和行骗识别为法术，从而和老千互动并不符合预期的BUG。现在垂钓和行骗将视为新牌名“连法”。

3. 修复了在受到法术加费光环的影响时，算法仍然会试图优先打出假币（硬币）的BUG。现在应当能够正确工作。

4. 修复了在被癫狂公爵交换手牌的情况下，手牌读取可能发生错误的BUG。现在应当能够正确工作。

5. 修复了一些曾经作用于手牌的buff，被buff的卡牌已经离开手牌后，buff仍然会作用到当前手牌，导致手牌读取发生错误的BUG。现在应当能够正确工作。

**以下为新特性**

6. 现在将目标值设置为999时，读取将不会改变目标值。这适用于始终希望计算最高伤害的情形。

7. 现在摁Ctrl可以读取（并且原先摁Enter就可以计算）。

8. 现在小键盘的数字键应该有效了。

9. 现在读取后会清空答案框。

10. 现在会将要挟当作1费的背刺。

11. 现在可以读取到更多的光环buff与手牌buff了，包括蛛魔拆解者、尼鲁巴、淤泥水管工这些光环buff，以及前沿哨所、诈死这些手牌buff。并且现在会将诈死当作2费普通法术了。

（原先可以读取塞布、持枪、女塞、涂粉这些光环buff，以及黑刀、暗影步、幻觉药水、腾武这些手牌buff）

12. 现在读取到的手牌顺序和游戏中应该一致了。随从顺序应该也一致，但是是从左到右而不是登场顺序。因此如果在实战中，如果随从的登场顺序不是从左到右，可能会导致幻觉药水的回手顺序和预期的不一致。

13. 现在读取的速度应当会比之前快一些，但是可能会多占用一些内存。

14. **随从血量特性** 现在手牌中的随从具有血量（在UI的最下一行），而场上的随从具有当前血量和总血量（在UI的向下倒数第五行和向下倒数第四行）。内部实现的状态做出了这样的改变，这将：

和背刺的互动更合理。尽管如此还是有“背刺不杀死友方随从时将不显示背刺目标”特性以及可能的其他特性。
  
**支持齿刺（锯齿骨刺），但目前仅支持对己方随从使用齿刺**。
  
算法效率可能有所降低。
  
算法在一些极端情况下可能无法搜索到最优解（即使已经穷尽）。

**当前版本已知特性：**

必然还有一些buff未被识别从而读取错误。

无法识别被沉默的随从（认为其异能仍然生效）。

与敌方随从有关的老问题：允许对同一个随从用两个背刺，或者前文提到的不能对敌方随从使用骨刺。

界面还需要优化：调整大小，简洁模式，一键同时读取计算，计算下回合，手动掐断，“关于”等。以及存在即使没有在进行计算，内存消耗仍然较高的问题。

还未添加和牌库的交互，和冰箱的交互，等等。

<br/>
<br/>
<br/>

**update[20220907]**

支持的情况基本都在UI上体现了。

可以手动添加法术、随从、战吼的加费光环。可以自动读入部分（写进去的）的加费光环。可以自动读入四项临时减费光环（XX层数）。

修改了费用读取逻辑，改为从原始费用开始维护所有真实增益，防止（真实）费用读取受到各类光环的影响。

目前UI支持鼠标和键盘，鼠标为选中-修改模式，键盘简化部分鼠标操作，支持上下左右移动选中（仅限手牌区和站场区），0-9修改数字（选中后首次修改从零起，可依次输入多位但有上限），backspace清除数字，字母修改牌名（根据二字短名的首字母），delete清除牌名，enter计算。

目前UI已经能保存读取路径至dft.txt中。

小提示1：将目标设置为999可以试图计算最高伤害。可以提高时限。

小提示2：如果想提前计算下个回合的斩杀线，在增加水晶之后还要记得把已用牌数清空。

小提示3：如果读取失败，可能是因为路径设置错误，或者路径下并不存在power.log，后者可能可以通过使用一次官方记牌器解决。

**基础使用方法被我放到开头了。**

（虽然看上去有Linux环境下的版本，但实际上不太有）
