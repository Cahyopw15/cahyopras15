import streamlit as st
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import time
import plotly.graph_objects as go
from supabase import create_client, Client
import json
from streamlit.components.v1 import html
from PIL import Image
from st_functions import st_button, load_css


@st.cache_resource
def init_connection():
    url = st.secrets["supabase_url"]
    key = st.secrets["supabase_key"]
    return create_client(url, key)

@st.cache_resource(ttl=15)
def run_query():
    return supabase.table("kebisingan2").select("*").order("id_kebisingan", desc=True).limit(4).execute()

def convert_dict_to_df(data):
    df = pd.DataFrame.from_dict(data)
    return df
    
st.sidebar.header('Dashboard Monitoring Kebisingan')
option = st.sidebar.selectbox(
    'Silakan pilih menu:',
    ('📊 Project','📝 About')
)
if option == '📊 Project':
    st.image("Logo_UnivLampung.png", width = 50)
    st.title("Real-Time Monitoring Pola Kebisingan Dashboard")
    placeholder = st.empty()    
    while True:
        supabase = init_connection()
        rows = run_query()
        rows = rows.model_dump_json()
        rows = json.loads(rows)
        if len(rows['data']) == 4:
            with placeholder.container():
                df = convert_dict_to_df(rows['data']).sort_values(by=["id_kebisingan"])
                z = df.iloc[0:4, 1:5].values
                #st.write(z)
                colorscale = [[0, 'darkviolet'], [0.5, 'yellowgreen'], [1, 'red']]
                fig = go.Figure(data=
                    go.Contour(
                        z = z, 
                        contours = dict(
                            coloring ='heatmap',
                            showlabels = True,
                            labelfont = dict(
                                size = 12,
                                color = 'black')) , 
                        colorscale = colorscale , 
                        colorbar=dict(
                            title='Kebisingan (dB)', # title here
                            titleside='right',
                            titlefont=dict(
                                size=14,
                                family='Extra Bold, sans-serif',
                                color = 'black'))))
                for j in range(4):
                    for k in range(4):
                        fig.add_annotation(x=j, y=k, text=str(z[j,k]), showarrow=False, font_size=14, font_color='black')
                fig.update_xaxes(visible = False)
                fig.update_yaxes(visible = False)
                fig.update_layout({"title":{"text":"<b>Pola Kebisingan 2 Dimensi</b>", "x":0.33, "y":0.85, "font": {"size":18}}} ,
                                  margin=dict(l=8, r=8, b=8, pad=8), plot_bgcolor='rgba(0,0,0,0)', paper_bgcolor='rgba(0,0,0,0)')
                st.plotly_chart(fig, theme="streamlit") 
                #st.markdown(
                    #'''
                    #<style>
                    #.streamlit-expanderHeader {
                        #background-color: #F0F8FF;
                        #color: black; # Adjust this for expander header color
                        #font-size : 35px;
                        #font-family : Arial;
                    #}
                    #.streamlit-expanderContent {
                        #background-color: #87CEEB;
                        #color: black; # Expander content color
                        #font-size : 20px;
                        #font-family : Arial;
                    #}
                    #</style>
                    #''',
                    #unsafe_allow_html=True
                #)
                #with st.expander("Detail Informasi"):
                    #st.write("""
                       #Gambar di atas merupakan hasil dari visualisasi tingkat kebisingan yang dihasilkan dari sensor suara.\n
                       #Daerah yang berwarna merah merupakan daerah yang tingkat kebisingannya sangat tinggi.\n
                       #Daerah yang berwarna hijau merupakan daerah yang tingkat kebisingannya normal.\n
                       #Daerah yang berwarna biru merupakan daerah yang tingkat kebisingannya rendah.\n
                       #""")
                fig_surface = go.Figure(data=[go.Surface(z=z, colorscale=colorscale, 
                                                        colorbar=dict(
                                                            title='Kebisingan (dB)', # title here
                                                            titleside='right',
                                                            titlefont=dict(
                                                                size=14,
                                                                family='Extra Bold, sans-serif',
                                                                color = 'black')))])
                fig_surface.update_layout( {"title":{"text":"<b>Pola Kebisingan 3 Dimensi</b>", "x":0.28, "y":0.85, "font": {"size":18}}},
                                            width=500, height=500, autosize=False, margin=dict(l = 65 ,  r = 50 ,  b = 65 ,  pad = 90), plot_bgcolor='rgba(0,0,0,0)', paper_bgcolor='rgba(0,0,0,0)')
                st.plotly_chart(fig_surface, theme="streamlit")
                #st.markdown(
                    #'''
                    #<style>
                    #.streamlit-expanderHeader {
                        #background-color: #F0F8FF;
                        #color: black; # Adjust this for expander header color
                        #font-size : 35px;
                        #font-family : Arial;
                    #}
                    #.streamlit-expanderContent {
                        #background-color: #87CEEB;
                        #color: black; # Expander content color
                        #font-size : 20px;
                        #font-family : Arial;
                    #}
                    #</style>
                    #''',
                    #unsafe_allow_html=True
                #)
                #with st.expander("Detail Informasi"):
                    #st.write("""
                       #Gambar di atas merupakan hasil dari visualisasi tingkat kebisingan yang dihasilkan dari sensor suara.\n
                      # Daerah yang berwarna merah merupakan daerah yang tingkat kebisingannya sangat tinggi.\n
                       #Daerah yang berwarna hijau merupakan daerah yang tingkat kebisingannya normal.\n
                      # Daerah yang berwarna biru merupakan daerah yang tingkat kebisingannya rendah.\n
                       #""")

                
        else:
            with placeholder.container():
                st.write("Not Enough Data!")
        time.sleep(1)
elif option == '📝 About':
    col11,col12, coll13 = st.columns(3)
    load_css()
    col1, col2, col3 = st.columns(3)
    col2.image(Image.open('Default_pfp.svg.png'))
    
    st.markdown("<h1 style='text-align: center; color:#2F4F4F;'>Cahyo Prasetiyo Wibowo</h1>", unsafe_allow_html=True)
    
    st.info('Pembuat Konten Mengenai Dashboard Monitoring Kebisingan')
        
    icon_size = 20

    st_button('Instagram', 'https://instagram.com/cahyoprasetiyowibowo?igshid=OGQ5ZDc2ODk2ZA==', 'Instagram', icon_size)
    st_button('Gmail', 'mailto::bobcahyo90@gmail.com', 'Gmail', icon_size)
    st_button('Github', 'https://github.com/Cahyopw15', 'Github', icon_size)
    #st_button('twitter', 'https://twitter.com/thedataprof/', 'Follow me on Twitter', icon_size)
    #st_button('linkedin', 'https://www.linkedin.com/in/chanin-nantasenamat/', 'Follow me on LinkedIn', icon_size)
    #st_button('newsletter', 'https://sendfox.com/dataprofessor/', 'Sign up for my Newsletter', icon_size)
    #st_button('cup', 'https://www.buymeacoffee.com/dataprofessor/', 'Buy me a Coffee', icon_size)






        

     
