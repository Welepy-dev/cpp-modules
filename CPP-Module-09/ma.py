from manim import *
import numpy as np

class FordJohnsonExplanation(Scene):
    def construct(self):
        # 1. Título e Lista Inicial
        title = Text("Algoritmo Ford-Johnson", color=BLUE).to_edge(UP)
        numbers = [31, 7, 12, 45, 2, 19, 8]
        elements = VGroup(*[
            Stack(Square(side_length=0.8), Text(str(n), font_size=24)) 
            for n in numbers
        ]).arrange(RIGHT, buff=0.5).shift(UP * 0.5)

        self.play(Write(title))
        self.play(Create(elements))
        self.wait()

        # 2. Fase de Emparelhamento (Pairing)
        step1_txt = Text("1. Emparelhamento e Comparação", font_size=24).next_to(title, DOWN)
        self.play(Write(step1_txt))
        
        # Destacando pares (Exemplo: 31 e 7)
        pair_rect = SurroundingRectangle(elements[0:2], color=YELLOW)
        self.play(Create(pair_rect))
        self.play(elements[0].animate.shift(UP*0.3), elements[1].animate.shift(DOWN*0.3))
        self.wait(0.5)
        
        # 3. Cadeia Principal vs Pendentes
        self.play(FadeOut(pair_rect), FadeOut(step1_txt))
        step2_txt = Text("2. Criar Cadeia Principal (Maiores de cada par)", font_size=24).next_to(title, DOWN)
        self.play(Write(step2_txt))
        
        # Simulação da separação
        main_chain = VGroup(*[elements[0], elements[3]]).arrange(RIGHT, buff=1).move_to(ORIGIN)
        pendants = VGroup(*[elements[1], elements[2]]).arrange(RIGHT, buff=1).next_to(main_chain, DOWN, buff=1)
        
        self.play(
            ReplacementTransform(elements, VGroup(main_chain, pendants)),
            run_time=2
        )
        self.wait()

        # 4. Inserção com Números de Jacobsthal
        self.play(FadeOut(step2_txt))
        step3_txt = Text("3. Inserção via Sequência de Jacobsthal", font_size=24).next_to(title, DOWN)
        jacob_text = Text("Sequência: 1, 3, 5, 11...", color=GREEN_A, font_size=20).next_to(step3_txt, DOWN)
        
        self.play(Write(step3_txt), Write(jacob_text))
        
        # Animação de um "pendente" subindo para a cadeia principal
        self.play(
            pendants[0].animate.move_to(main_chain[0].get_left() + LEFT*0.5),
            main_chain.animate.shift(RIGHT*0.5)
        )
        
        self.wait(2)
        self.play(FadeOut(VGroup(title, main_chain, pendants, step3_txt, jacob_text)))

# Auxiliar para agrupar o quadrado e o texto
def Stack(shape, text):
    return VGroup(shape, text)
