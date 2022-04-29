import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtCharts 6.2

Window {
    width: 740
    height: 480
    visible: true
    // title: qsTr("Arnold's Wave Drawer")
    title: qsTr("窗口画图小程序")
    property int timer: 0

    Button {
        id: loadButton
        x: 627
        y: 430
        text: qsTr("加载数据")
        onClicked: {
            for (var sig in load())
            {
                waveTextArea.append(sig)
            }
        }
    }

    Button {
        id: saveButton
        x: 627
        y: 377
        text: qsTr("存储数据")
        onClicked: {

        }
    }

    TextArea {
        id: waveTextArea
        x: 22
        y: 305
        width: 591
        height: 165
        placeholderText: qsTr("Wave Data")
        /*background: Rectangle{
            color: "gray"
        }*/
        text:
'2033 2033 2028 2022 2015 2007 2000 1988 1981 1971 1963 1961 1966 1967 1968 1967 1965 1960
1960 1963 1961 1963 1951 1952 1955 1957 1956 1961 1958 1957 1956 1952 1953 1955 1956 1957
1957 1963 1959 1956 1954 1955 1952 1955 1956 1958 1957 1961 1958 1957 1956 1955 1953 1953
1958 1960 1959 1962 1961 1957 1955 1957 1953 1959 1956 1960 1958 1959 1958 1959 1956 1955
1951 1956 1957 1962 1959 1960 1962 1957 1957 1956 1960 1969 1981 1989 1999 2010 2014 2021
2026 2029 2028 2034 2041 2047 2049 2058 2056 2055 2054 2052 2051 2054 2051 2059 2056 2053
2045 2039 2037 2028 2024 2021 2017 2005 2002 1995 1986 1977 1967 1959 1952 1957 1958 1957
1962 1961 1960 1957 1956 1956 1956 1956 1957 1955 1961 1961 1963 1958 1955 1956 1956 1958
1958 1960 1962 1960 1959 1961 1955 1957 1957 1959 1959 1959 1962 1966 1962 1941 1914 1885
1859 1833 1807 1858 1940 2022 2102 2178 2255 2333 2410 2493 2575 2649 2732 2755 2754 2681
2590 2498 2412 2313 2217 2131 2038 1947 1847 1755 1665 1680 1726 1781 1838 1889 1944 1958'
    }

    ChartView {
        id: waveChartView
        x: 22
        y: 36
        width: 591
        height: 264
        antialiasing: true
        // backgroundColor: "#9917719b"
        animationOptions: ChartView.SeriesAnimations
        legend.visible:false
/*
        ValueAxis {
                 id: myAxisX
                 min: 0
                 tickCount: 11
                 labelsColor: "#ffffff"
                 labelsFont.pointSize: 13
                 labelsFont.bold: true
                 labelFormat: '%d'
             }
        ValueAxis{
            id:myAxisY
            tickCount: 6
            labelsColor: "#ffffff"
            labelsFont.pointSize: 13
            labelsFont.bold: true
            labelFormat: '%d'
        }
        */

        LineSeries {
            id:lineSeries
            axisX: myAxisX
            axisY: myAxisY
            name: "LineSeries"
            //color: "#00ffff"
            width: 3

            XYPoint { x: 0; y: 2033}
            XYPoint { x: 1; y: 2033}
            XYPoint { x: 2; y: 2028}
            XYPoint { x: 3; y: 2022}
            XYPoint { x: 4; y: 2015}
            XYPoint { x: 5; y: 2007}
            XYPoint { x: 6; y: 2000}
            XYPoint { x: 7; y: 1988}
            XYPoint { x: 8; y: 1981}
            XYPoint { x: 9; y: 1971}
            XYPoint { x: 10; y: 1963}
            XYPoint { x: 11; y: 1961}
            XYPoint { x: 12; y: 1966}
            XYPoint { x: 13; y: 1967}
            XYPoint { x: 14; y: 1968}
            XYPoint { x: 15; y: 1967}
            XYPoint { x: 16; y: 1965}
            XYPoint { x: 17; y: 1960}
            XYPoint { x: 18; y: 1960}
            XYPoint { x: 19; y: 1963}
            XYPoint { x: 20; y: 1961}
            XYPoint { x: 21; y: 1963}
            XYPoint { x: 22; y: 1951}
            XYPoint { x: 23; y: 1952}
            XYPoint { x: 24; y: 1955}
            XYPoint { x: 25; y: 1957}
            XYPoint { x: 26; y: 1956}
            XYPoint { x: 27; y: 1961}
            XYPoint { x: 28; y: 1958}
            XYPoint { x: 29; y: 1957}
            XYPoint { x: 30; y: 1956}
            XYPoint { x: 31; y: 1952}
            XYPoint { x: 32; y: 1953}
            XYPoint { x: 33; y: 1955}
            XYPoint { x: 34; y: 1956}
            XYPoint { x: 35; y: 1957}
            XYPoint { x: 36; y: 1957}
            XYPoint { x: 37; y: 1963}
            XYPoint { x: 38; y: 1959}
            XYPoint { x: 39; y: 1956}
            XYPoint { x: 40; y: 1954}
            XYPoint { x: 41; y: 1955}
            XYPoint { x: 42; y: 1952}
            XYPoint { x: 43; y: 1955}
            XYPoint { x: 44; y: 1956}
            XYPoint { x: 45; y: 1958}
            XYPoint { x: 46; y: 1957}
            XYPoint { x: 47; y: 1961}
            XYPoint { x: 48; y: 1958}
            XYPoint { x: 49; y: 1957}
            XYPoint { x: 50; y: 1956}
            XYPoint { x: 51; y: 1955}
            XYPoint { x: 52; y: 1953}
            XYPoint { x: 53; y: 1953}
            XYPoint { x: 54; y: 1958}
            XYPoint { x: 55; y: 1960}
            XYPoint { x: 56; y: 1959}
            XYPoint { x: 57; y: 1962}
            XYPoint { x: 58; y: 1961}
            XYPoint { x: 59; y: 1957}
            XYPoint { x: 60; y: 1955}
            XYPoint { x: 61; y: 1957}
            XYPoint { x: 62; y: 1953}
            XYPoint { x: 63; y: 1959}
            XYPoint { x: 64; y: 1956}
            XYPoint { x: 65; y: 1960}
            XYPoint { x: 66; y: 1958}
            XYPoint { x: 67; y: 1959}
            XYPoint { x: 68; y: 1958}
            XYPoint { x: 69; y: 1959}
            XYPoint { x: 70; y: 1956}
            XYPoint { x: 71; y: 1955}
            XYPoint { x: 72; y: 1951}
            XYPoint { x: 73; y: 1956}
            XYPoint { x: 74; y: 1957}
            XYPoint { x: 75; y: 1962}
            XYPoint { x: 76; y: 1959}
            XYPoint { x: 77; y: 1960}
            XYPoint { x: 78; y: 1962}
            XYPoint { x: 79; y: 1957}
            XYPoint { x: 80; y: 1957}
            XYPoint { x: 81; y: 1956}
            XYPoint { x: 82; y: 1960}
            XYPoint { x: 83; y: 1969}
            XYPoint { x: 84; y: 1981}
            XYPoint { x: 85; y: 1989}
            XYPoint { x: 86; y: 1999}
            XYPoint { x: 87; y: 2010}
            XYPoint { x: 88; y: 2014}
            XYPoint { x: 89; y: 2021}
            XYPoint { x: 90; y: 2026}
            XYPoint { x: 91; y: 2029}
            XYPoint { x: 92; y: 2028}
            XYPoint { x: 93; y: 2034}
            XYPoint { x: 94; y: 2041}
            XYPoint { x: 95; y: 2047}
            XYPoint { x: 96; y: 2049}
            XYPoint { x: 97; y: 2058}
            XYPoint { x: 98; y: 2056}
            XYPoint { x: 99; y: 2055}
            XYPoint { x: 100; y: 2054}
            XYPoint { x: 101; y: 2052}
            XYPoint { x: 102; y: 2051}
            XYPoint { x: 103; y: 2054}
            XYPoint { x: 104; y: 2051}
            XYPoint { x: 105; y: 2059}
            XYPoint { x: 106; y: 2056}
            XYPoint { x: 107; y: 2053}
            XYPoint { x: 108; y: 2045}
            XYPoint { x: 109; y: 2039}
            XYPoint { x: 110; y: 2037}
            XYPoint { x: 111; y: 2028}
            XYPoint { x: 112; y: 2024}
            XYPoint { x: 113; y: 2021}
            XYPoint { x: 114; y: 2017}
            XYPoint { x: 115; y: 2005}
            XYPoint { x: 116; y: 2002}
            XYPoint { x: 117; y: 1995}
            XYPoint { x: 118; y: 1986}
            XYPoint { x: 119; y: 1977}
            XYPoint { x: 120; y: 1967}
            XYPoint { x: 121; y: 1959}
            XYPoint { x: 122; y: 1952}
            XYPoint { x: 123; y: 1957}
            XYPoint { x: 124; y: 1958}
            XYPoint { x: 125; y: 1957}
            XYPoint { x: 126; y: 1962}
            XYPoint { x: 127; y: 1961}
            XYPoint { x: 128; y: 1960}
            XYPoint { x: 129; y: 1957}
            XYPoint { x: 130; y: 1956}
            XYPoint { x: 131; y: 1956}
            XYPoint { x: 132; y: 1956}
            XYPoint { x: 133; y: 1956}
            XYPoint { x: 134; y: 1957}
            XYPoint { x: 135; y: 1955}
            XYPoint { x: 136; y: 1961}
            XYPoint { x: 137; y: 1961}
            XYPoint { x: 138; y: 1963}
            XYPoint { x: 139; y: 1958}
            XYPoint { x: 140; y: 1955}
            XYPoint { x: 141; y: 1956}
            XYPoint { x: 142; y: 1956}
            XYPoint { x: 143; y: 1958}
            XYPoint { x: 144; y: 1958}
            XYPoint { x: 145; y: 1960}
            XYPoint { x: 146; y: 1962}
            XYPoint { x: 147; y: 1960}
            XYPoint { x: 148; y: 1959}
            XYPoint { x: 149; y: 1961}
            XYPoint { x: 150; y: 1955}
            XYPoint { x: 151; y: 1957}
            XYPoint { x: 152; y: 1957}
            XYPoint { x: 153; y: 1959}
            XYPoint { x: 154; y: 1959}
            XYPoint { x: 155; y: 1959}
            XYPoint { x: 156; y: 1962}
            XYPoint { x: 157; y: 1966}
            XYPoint { x: 158; y: 1962}
            XYPoint { x: 159; y: 1941}
            XYPoint { x: 160; y: 1914}
            XYPoint { x: 161; y: 1885}
            XYPoint { x: 162; y: 1859}
            XYPoint { x: 163; y: 1833}
            XYPoint { x: 164; y: 1807}
            XYPoint { x: 165; y: 1858}
            XYPoint { x: 166; y: 1940}
            XYPoint { x: 167; y: 2022}
            XYPoint { x: 168; y: 2102}
            XYPoint { x: 169; y: 2178}
            XYPoint { x: 170; y: 2255}
            XYPoint { x: 171; y: 2333}
            XYPoint { x: 172; y: 2410}
            XYPoint { x: 173; y: 2493}
            XYPoint { x: 174; y: 2575}
            XYPoint { x: 175; y: 2649}
            XYPoint { x: 176; y: 2732}
            XYPoint { x: 177; y: 2755}
            XYPoint { x: 178; y: 2754}
            XYPoint { x: 179; y: 2681}
            XYPoint { x: 180; y: 2590}
            XYPoint { x: 181; y: 2498}
            XYPoint { x: 182; y: 2412}
            XYPoint { x: 183; y: 2313}
            XYPoint { x: 184; y: 2217}
            XYPoint { x: 185; y: 2131}
            XYPoint { x: 186; y: 2038}
            XYPoint { x: 187; y: 1947}
            XYPoint { x: 188; y: 1847}
            XYPoint { x: 189; y: 1755}
            XYPoint { x: 190; y: 1665}
            XYPoint { x: 191; y: 1680}
            XYPoint { x: 192; y: 1726}
            XYPoint { x: 193; y: 1781}
            XYPoint { x: 194; y: 1838}
            XYPoint { x: 195; y: 1889}
            XYPoint { x: 196; y: 1944}
            XYPoint { x: 197; y: 1958}
            XYPoint { x: 198; y: 1960}
            XYPoint { x: 199; y: 1957}
            XYPoint { x: 200; y: 1956}
            XYPoint { x: 201; y: 1959}
            XYPoint { x: 202; y: 1955}
            XYPoint { x: 203; y: 1963}
            XYPoint { x: 204; y: 1961}
            XYPoint { x: 205; y: 1964}
            XYPoint { x: 206; y: 1966}
            XYPoint { x: 207; y: 1972}
            XYPoint { x: 208; y: 1969}
            XYPoint { x: 209; y: 1969}
            XYPoint { x: 210; y: 1967}
            XYPoint { x: 211; y: 1969}
            XYPoint { x: 212; y: 1971}
            XYPoint { x: 213; y: 1972}
            XYPoint { x: 214; y: 1974}
            XYPoint { x: 215; y: 1975}
            XYPoint { x: 216; y: 1982}
            XYPoint { x: 217; y: 1984}
            XYPoint { x: 218; y: 1983}
            XYPoint { x: 219; y: 1987}
            XYPoint { x: 220; y: 1983}
            XYPoint { x: 221; y: 1983}
            XYPoint { x: 222; y: 1987}
            XYPoint { x: 223; y: 1991}
            XYPoint { x: 224; y: 1991}
            XYPoint { x: 225; y: 1996}
            XYPoint { x: 226; y: 1998}
            XYPoint { x: 227; y: 2005}
            XYPoint { x: 228; y: 2003}
            XYPoint { x: 229; y: 2006}
            XYPoint { x: 230; y: 2002}
            XYPoint { x: 231; y: 2006}
            XYPoint { x: 232; y: 2007}
            XYPoint { x: 233; y: 2013}
            XYPoint { x: 234; y: 2018}
            XYPoint { x: 235; y: 2021}
            XYPoint { x: 236; y: 2025}
            XYPoint { x: 237; y: 2030}
            XYPoint { x: 238; y: 2031}
            XYPoint { x: 239; y: 2033}
            XYPoint { x: 240; y: 2028}
            XYPoint { x: 241; y: 2033}
            XYPoint { x: 242; y: 2034}
            XYPoint { x: 243; y: 2036}
            XYPoint { x: 244; y: 2041}
            XYPoint { x: 245; y: 2043}
            XYPoint { x: 246; y: 2049}
            XYPoint { x: 247; y: 2054}
            XYPoint { x: 248; y: 2051}
            XYPoint { x: 249; y: 2054}
            XYPoint { x: 250; y: 2054}
            XYPoint { x: 251; y: 2060}
            XYPoint { x: 252; y: 2059}
            XYPoint { x: 253; y: 2062}
            XYPoint { x: 254; y: 2067}
            XYPoint { x: 255; y: 2070}
            XYPoint { x: 256; y: 2073}
            XYPoint { x: 257; y: 2081}
            XYPoint { x: 258; y: 2079}
            XYPoint { x: 259; y: 2079}
            XYPoint { x: 260; y: 2076}
            XYPoint { x: 261; y: 2080}
            XYPoint { x: 262; y: 2079}
            XYPoint { x: 263; y: 2085}
            XYPoint { x: 264; y: 2090}
            XYPoint { x: 265; y: 2091}
            XYPoint { x: 266; y: 2099}
            XYPoint { x: 267; y: 2106}
            XYPoint { x: 268; y: 2107}
            XYPoint { x: 269; y: 2106}
            XYPoint { x: 270; y: 2108}
            XYPoint { x: 271; y: 2110}
            XYPoint { x: 272; y: 2106}
            XYPoint { x: 273; y: 2110}
            XYPoint { x: 274; y: 2117}
            XYPoint { x: 275; y: 2116}
            XYPoint { x: 276; y: 2122}
            XYPoint { x: 277; y: 2128}
            XYPoint { x: 278; y: 2127}
            XYPoint { x: 279; y: 2130}
            XYPoint { x: 280; y: 2131}
            XYPoint { x: 281; y: 2141}
            XYPoint { x: 282; y: 2143}
            XYPoint { x: 283; y: 2155}
            XYPoint { x: 284; y: 2164}
            XYPoint { x: 285; y: 2169}
            XYPoint { x: 286; y: 2180}
            XYPoint { x: 287; y: 2184}
            XYPoint { x: 288; y: 2188}
            XYPoint { x: 289; y: 2188}
            XYPoint { x: 290; y: 2191}
            XYPoint { x: 291; y: 2195}
            XYPoint { x: 292; y: 2195}
            XYPoint { x: 293; y: 2205}
            XYPoint { x: 294; y: 2209}
            XYPoint { x: 295; y: 2204}
            XYPoint { x: 296; y: 2201}
            XYPoint { x: 297; y: 2197}
            XYPoint { x: 298; y: 2186}
            XYPoint { x: 299; y: 2178}
            XYPoint { x: 300; y: 2171}
            XYPoint { x: 301; y: 2164}
            XYPoint { x: 302; y: 2156}
            XYPoint { x: 303; y: 2156}
            XYPoint { x: 304; y: 2152}
            XYPoint { x: 305; y: 2150}
            XYPoint { x: 306; y: 2146}
            XYPoint { x: 307; y: 2149}
            XYPoint { x: 308; y: 2139}
            XYPoint { x: 309; y: 2136}
            XYPoint { x: 310; y: 2132}
            XYPoint { x: 311; y: 2123}
            XYPoint { x: 312; y: 2109}
            XYPoint { x: 313; y: 2094}
            XYPoint { x: 314; y: 2080}
            XYPoint { x: 315; y: 2067}
            XYPoint { x: 316; y: 2051}
            XYPoint { x: 317; y: 2036}
            XYPoint { x: 318; y: 2018}
            XYPoint { x: 319; y: 2001}
            XYPoint { x: 320; y: 1996}
            XYPoint { x: 321; y: 1986}
            XYPoint { x: 322; y: 1983}
            XYPoint { x: 323; y: 1973}
            XYPoint { x: 324; y: 1972}
            XYPoint { x: 325; y: 1969}
            XYPoint { x: 326; y: 1963}
            XYPoint { x: 327; y: 1959}
            XYPoint { x: 328; y: 1956}
            XYPoint { x: 329; y: 1953}
            XYPoint { x: 330; y: 1952}
            XYPoint { x: 331; y: 1951}
            XYPoint { x: 332; y: 1948}
            XYPoint { x: 333; y: 1953}

        }


    }
/*
    Timer{
        interval: 10
        running: true
        repeat: true
        onTriggered: {
            lineSeries.append(timer,Math.random()*50)
            if (timer > 100)
            {
                timer = 0
                lineSeries.clear()
            }
            else
            {
                timer += 1
            }
        }
    }
*/
    RadioButton {
        id: radioButton
        x: 627
        y: 71
        text: "静态显示"
        checkable: false
    }

    RadioButton {
        id: radioButton1
        x: 627
        y: 100
        text: qsTr("动态显示")
    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.33}
}
##^##*/
