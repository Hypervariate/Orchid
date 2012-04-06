//  Copyright (c) 2007 John Maddock
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

   static const boost::array<boost::array<T, 3>, 70> bessel_j_large_data = {{
      {{ SC_(0.725889492034912109375e1), SC_(0.725889492034912109375e1), SC_(0.2307850131230964328215158373258970201933e0) }}, 
      {{ SC_(0.725889492034912109375e1), SC_(0.90838165283203125e1), SC_(0.331270090805281544869225081474258975783e0) }}, 
      {{ SC_(0.725889492034912109375e1), SC_(0.30492671966552734375e2), SC_(0.1392044369140870127137144436194280008198e0) }}, 
      {{ SC_(0.725889492034912109375e1), SC_(0.5872027587890625e2), SC_(-0.1034372792561996393994604565745500159306e0) }}, 
      {{ SC_(0.725889492034912109375e1), SC_(0.7212715911865234375e2), SC_(-0.7703453431004507456085858477671512851731e-1) }}, 
      {{ SC_(0.725889492034912109375e1), SC_(0.25201507568359375e3), SC_(0.1959284506006571693892495807977692143684e-1) }}, 
      {{ SC_(0.725889492034912109375e1), SC_(0.48982421875e3), SC_(0.3554545809249573170321495025893136154241e-1) }}, 
      {{ SC_(0.725889492034912109375e1), SC_(0.62516943359375e3), SC_(-0.2922687275543058917680294015955588486854e-1) }}, 
      {{ SC_(0.725889492034912109375e1), SC_(0.1671535888671875e4), SC_(0.1607375857460556311523938125070882107754e-1) }}, 
      {{ SC_(0.725889492034912109375e1), SC_(0.26791259765625e4), SC_(-0.1488078416329900906439423002725322373542e-1) }}, 
      {{ SC_(0.725889492034912109375e1), SC_(0.4495525390625e4), SC_(-0.1140024419570086978904733358200459324628e-1) }}, 
      {{ SC_(0.725889492034912109375e1), SC_(0.126748310546875e5), SC_(-0.3122722904155054704789731376588374939888e-2) }}, 
      {{ SC_(0.725889492034912109375e1), SC_(0.209469140625e5), SC_(0.3655895534999378610724150587348023983602e-2) }}, 
      {{ SC_(0.725889492034912109375e1), SC_(0.389408984375e5), SC_(-0.1325113645945403697015197310014126427368e-2) }}, 
      {{ SC_(0.90838165283203125e1), SC_(0.725889492034912109375e1), SC_(0.6868013625729672215673766261089739717914e-1) }}, 
      {{ SC_(0.90838165283203125e1), SC_(0.90838165283203125e1), SC_(0.2142196934269988501665220845763503388042e0) }}, 
      {{ SC_(0.90838165283203125e1), SC_(0.30492671966552734375e2), SC_(-0.6854165161240333873733646364329358362341e-1) }}, 
      {{ SC_(0.90838165283203125e1), SC_(0.5872027587890625e2), SC_(0.9706365272921634392020123576878096972323e-1) }}, 
      {{ SC_(0.90838165283203125e1), SC_(0.7212715911865234375e2), SC_(0.4318373430471325672009672522183904089517e-1) }}, 
      {{ SC_(0.90838165283203125e1), SC_(0.25201507568359375e3), SC_(-0.3323948817558893756314993595448795803537e-2) }}, 
      {{ SC_(0.90838165283203125e1), SC_(0.48982421875e3), SC_(-0.3208784009186279824559250801925804018465e-1) }}, 
      {{ SC_(0.90838165283203125e1), SC_(0.62516943359375e3), SC_(0.2415910850536018880522735141575176512777e-1) }}, 
      {{ SC_(0.90838165283203125e1), SC_(0.1671535888671875e4), SC_(-0.1232973481208096922064985021712946282434e-1) }}, 
      {{ SC_(0.90838165283203125e1), SC_(0.26791259765625e4), SC_(0.1541293552432680038181584370193664107473e-1) }}, 
      {{ SC_(0.90838165283203125e1), SC_(0.4495525390625e4), SC_(0.1002388002178436742775036807597412212988e-1) }}, 
      {{ SC_(0.90838165283203125e1), SC_(0.126748310546875e5), SC_(0.4739251557631330719337662497765662043458e-2) }}, 
      {{ SC_(0.90838165283203125e1), SC_(0.209469140625e5), SC_(-0.4641170982395964367850932352617365960394e-2) }}, 
      {{ SC_(0.90838165283203125e1), SC_(0.389408984375e5), SC_(0.2364161829230146293999578445914286938024e-3) }}, 
      {{ SC_(0.30492671966552734375e2), SC_(0.725889492034912109375e1), SC_(0.5389197635915806233390841938474448086338e-16) }}, 
      {{ SC_(0.30492671966552734375e2), SC_(0.90838165283203125e1), SC_(0.3952459558161787055937696735475346378253e-13) }}, 
      {{ SC_(0.30492671966552734375e2), SC_(0.30492671966552734375e2), SC_(0.1431568992863962918440953734528390055733e0) }}, 
      {{ SC_(0.30492671966552734375e2), SC_(0.5872027587890625e2), SC_(0.8578089143574435265609743500241838450074e-1) }}, 
      {{ SC_(0.30492671966552734375e2), SC_(0.7212715911865234375e2), SC_(0.1410641386118672963443531500494113618346e-1) }}, 
      {{ SC_(0.30492671966552734375e2), SC_(0.25201507568359375e3), SC_(-0.2831444492336412069372220459848882424058e-1) }}, 
      {{ SC_(0.30492671966552734375e2), SC_(0.48982421875e3), SC_(-0.2314909531023927534092551249336846514091e-1) }}, 
      {{ SC_(0.30492671966552734375e2), SC_(0.62516943359375e3), SC_(0.2170848675622913630936132875332654675284e-1) }}, 
      {{ SC_(0.30492671966552734375e2), SC_(0.1671535888671875e4), SC_(-0.9325685551001457451901386831696429723505e-2) }}, 
      {{ SC_(0.30492671966552734375e2), SC_(0.26791259765625e4), SC_(-0.6947960924639771467867037818061032165711e-2) }}, 
      {{ SC_(0.30492671966552734375e2), SC_(0.4495525390625e4), SC_(0.2522782171073615304290664333918949926448e-3) }}, 
      {{ SC_(0.30492671966552734375e2), SC_(0.126748310546875e5), SC_(-0.7032986459719800448169085872312178500116e-2) }}, 
      {{ SC_(0.30492671966552734375e2), SC_(0.209469140625e5), SC_(0.5122201654532113914038286303179605549787e-2) }}, 
      {{ SC_(0.30492671966552734375e2), SC_(0.389408984375e5), SC_(0.3118763746002366768916876665037341197225e-2) }}, 
      {{ SC_(0.5872027587890625e2), SC_(0.725889492034912109375e1), SC_(0.1355459268067898658151384249990581267605e-46) }}, 
      {{ SC_(0.5872027587890625e2), SC_(0.90838165283203125e1), SC_(0.6263805301401313877353888242546513061021e-41) }}, 
      {{ SC_(0.5872027587890625e2), SC_(0.30492671966552734375e2), SC_(0.1202543691751492070742433226952612421088e-11) }}, 
      {{ SC_(0.5872027587890625e2), SC_(0.5872027587890625e2), SC_(0.1150759176943336800292116211528794948354e0) }}, 
      {{ SC_(0.5872027587890625e2), SC_(0.7212715911865234375e2), SC_(-0.1047430440042659670890981946453377232975e-2) }}, 
      {{ SC_(0.5872027587890625e2), SC_(0.25201507568359375e3), SC_(-0.4086747435836167042364362710950743904056e-1) }}, 
      {{ SC_(0.5872027587890625e2), SC_(0.48982421875e3), SC_(-0.8183965550065315841115618961272005737216e-2) }}, 
      {{ SC_(0.5872027587890625e2), SC_(0.62516943359375e3), SC_(0.2146006391006581305906226294562488601133e-1) }}, 
      {{ SC_(0.5872027587890625e2), SC_(0.1671535888671875e4), SC_(-0.1521907719127834149642973426124244709606e-1) }}, 
      {{ SC_(0.5872027587890625e2), SC_(0.26791259765625e4), SC_(-0.5359901862639028443437495673595828567149e-2) }}, 
      {{ SC_(0.5872027587890625e2), SC_(0.4495525390625e4), SC_(-0.6687847432133282099926443966258547872974e-3) }}, 
      {{ SC_(0.5872027587890625e2), SC_(0.126748310546875e5), SC_(-0.7023133406228636526878960014610930229604e-2) }}, 
      {{ SC_(0.5872027587890625e2), SC_(0.209469140625e5), SC_(0.5494684780269989275230320303506992388372e-2) }}, 
      {{ SC_(0.5872027587890625e2), SC_(0.389408984375e5), SC_(0.2133199464416083487500787075862183481877e-2) }}, 
      {{ SC_(0.7212715911865234375e2), SC_(0.725889492034912109375e1), SC_(0.18957209567263693085259721077483394587e-63) }}, 
      {{ SC_(0.7212715911865234375e2), SC_(0.90838165283203125e1), SC_(0.18129450849783963899751662717930347867e-56) }}, 
      {{ SC_(0.7212715911865234375e2), SC_(0.30492671966552734375e2), SC_(0.799552979179394942566748705329500029705e-20) }}, 
      {{ SC_(0.7212715911865234375e2), SC_(0.5872027587890625e2), SC_(0.1552366431895120369074625091623203198931e-3) }}, 
      {{ SC_(0.7212715911865234375e2), SC_(0.7212715911865234375e2), SC_(0.1074534531973475595081469483471348487375e0) }}, 
      {{ SC_(0.7212715911865234375e2), SC_(0.25201507568359375e3), SC_(-0.4021841759432511100331858349923571437074e-1) }}, 
      {{ SC_(0.7212715911865234375e2), SC_(0.48982421875e3), SC_(-0.2170518020212747257681494905588835722404e-1) }}, 
      {{ SC_(0.7212715911865234375e2), SC_(0.62516943359375e3), SC_(0.3200282452240180595697263016953209545847e-1) }}, 
      {{ SC_(0.7212715911865234375e2), SC_(0.1671535888671875e4), SC_(0.1388345457492732160509267345077835744377e-1) }}, 
      {{ SC_(0.7212715911865234375e2), SC_(0.26791259765625e4), SC_(-0.1211552634023650615661641900044154973817e-1) }}, 
      {{ SC_(0.7212715911865234375e2), SC_(0.4495525390625e4), SC_(-0.1044260623905249384981833094590727496255e-1) }}, 
      {{ SC_(0.7212715911865234375e2), SC_(0.126748310546875e5), SC_(0.4589655631278176598474380175755836047107e-2) }}, 
      {{ SC_(0.7212715911865234375e2), SC_(0.209469140625e5), SC_(-0.2719723241223086004132685612975137005354e-2) }}, 
      {{ SC_(0.7212715911865234375e2), SC_(0.389408984375e5), SC_(-0.4035830877477336799210808243472842844322e-2) }}
   }};


