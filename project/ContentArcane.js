let Arcaneimages = [
    "https://assets2.rockpapershotgun.com/league-of-legends-arcane-series-netflix.jpg/BROK/resize/1920x1920%3E/format/jpg/quality/80/league-of-legends-arcane-series-netflix.jpg"
    "https://cdn1.dotesports.com/wp-content/uploads/2021/11/06191657/Arcane_Jayce_Final-1536x864.jpg"
    "https://imgix.bustle.com/uploads/image/2021/11/17/5c8189de-caf8-4db8-93f7-a151119da033-jinx-arcane.jpg?w=2000&h=640&fit=crop&crop=faces&auto=format%2Ccompress"
    "https://cdnportal.mobalytics.gg/production/2021/10/a17c06f1-jinx.png"
    "https://cdnportal.mobalytics.gg/production/2021/10/2cfec732-caitlyn.png"
    "https://cdnportal.mobalytics.gg/production/2021/10/14f522df-heimerdinger.png"
    "https://cdnportal.mobalytics.gg/production/2021/10/6e3a6a0c-ekko.png"
    "https://cdnportal.mobalytics.gg/production/2021/10/c6473442-jayce.png"
    ];
    
    const im = document.getElementsByTagName("img");
    for (let i = 0; i < im.length; i++) {
        const randomImg = Math.floor(Math.random() * Arcaneimages.length);
        im[i].src = Arcaneimages[randomImg];
    }
    const header = document.getElementsByTagName("h1");
    for (let i = 0; i < header.length; i++) {
        header[i].innerText = "Arcane";
    }
    
    
